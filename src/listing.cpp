#include "stock.hpp"
#include "time_utils.hpp"
#include "curl_utils.hpp"

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
	ss << this.stocks.size();

	std::string error = "ERROR: getStock(index) - Index must be smaller than" + ss.str();
	throw std::invalid_argument(error);
}

Stock Listing::getStock(std::time_t date){
	for(std::vector<Stock>::iterator it = this->stocks.begin(); it != this->stocks.end(); ++it){
		if(it->getDate() == date) return *it;
	}
	
	std::string error = "ERROR: getStock(date) - There is no Stock at " + date;
	throw std::invalid_argument(error);
}

Stock Listing::getStock(std::string date){
	for(std::vector<Stock>::iterator it = this->stocks.begin(); it != this->stocks.end(); ++it){
		if(it->getDateToString() == date) return *it;
	}

	std::string error = "ERROR: getStock(date) - There is no Stock at " + date;
	std::invalid_argument(error);
}

void Listing::printStocks(){
	for(std::vector<Stock>::iterator it = this->stocks.begin(); it != this.stocks.end(); ++it){
		std::cout << it->toString() << endl;
	}
}

void Listing::clearStocks(){
	this->stocks.clear();
}

std::string Listing::getHistoricalStocks(
