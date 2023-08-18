#include <iostream>
#include <sstream>

#include "curl_utils.hpp"
#include <curl/curl.h>

size_t writecallback(char *contents, size_t size, size_t nmemb, void *userdata){
      	size_t realSize = size * nmemb;
        
	// Append the content to user data
	((std::string*)userdata)->append(contents, realSize); 
	
	return realSize;
}

std::string getStockData(std::string symbol){
	std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY_ADJUSTED&symbol="+symbol+"&interval=5min&apikey=1166DVY0CGSAJ47I&";
	
	CURL *curl = curl_easy_init();
	std::string responseBuffer;

        if(curl){

                curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
		
		// Write result in buffer
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
		curl_easy_setopt(curl,CURLOPT_WRITEDATA, &responseBuffer);

		// Perform the request
                CURLcode result = curl_easy_perform(curl);

		// cleanup
                curl_easy_cleanup(curl);
        }
	
	return responseBuffer;
}

void getHistoricalData(std::string symbol){
	std::string csv = getStockData(symbol);
	std::stringstream csvStream(csv);
	std::string line;

	//Remove the header line
	std::getline(csvStream,line);
	
	std::vector<std::string> stockVector;
	while(std::getline(csvStream, line)){
		std::stringstream iss(line);
		std::string lineItem;
	
		while(std::getline(iss, lineItem, ',')){
			stockVector.push_back(lineItem);
		}
	}

	for(int i=0;i<stockVector.size();i++){
		std::cout<<stockVector[i]<<std::endl;
	}
}
