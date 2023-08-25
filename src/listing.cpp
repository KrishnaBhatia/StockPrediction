#include "stock.hpp"
#include "time_utils.hpp"
#include "curl_utils.hpp"
#include "listing.hpp"

#include <iostream>
#include <sstream>
#include <curl/curl.h>

Listing::Listing(std::string symbol){
	this->symbol = symbol;
}

Listing::~Listing() {}

size_t Listing::nbStocks(){
	return this->stocks.size();
}

Stock Listing::getStock(size_t i){
	if(i < this->stocks.size()){
		return this->stocks[i];
	}

	std::stringstream ss;
	ss << this->stocks.size();

	std::string error = "ERROR: getStock(index) - Index must be smaller than" + ss.str();
	std::cout << error << std::endl;
}

Stock Listing::getStock(std::time_t date){
	for(std::vector<Stock>::iterator it = this->stocks.begin(); it != this->stocks.end(); ++it){
		if(it->getDate() == date) return *it;
	}
	
	std::string error = "ERROR: getStock(date) - There is no Stock at ";
	std::cout << error << std::endl;
}

Stock Listing::getStock(std::string date){
	for(std::vector<Stock>::iterator it = this->stocks.begin(); it != this->stocks.end(); ++it){
		if(it->getDateToString() == date) return *it;
	}

	std::string error = "ERROR: getStock(date) - There is no Stock at " + date;
	std::cout << error << std::endl;
}

void Listing::printStocks(){
	for(std::vector<Stock>::iterator it = this->stocks.begin(); it != this->stocks.end(); ++it){
		std::cout << it->toString() << std::endl;
	}
}

void Listing::clearStocks(){
	this->stocks.clear();
}

void Listing::getHistoricalData(std::string symbol){
        std::string csv = getStockData(this->symbol);
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
                std::cout << stockVector[i] << std::endl;
        }
}
