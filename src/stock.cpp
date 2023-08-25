#include "time_utils.hpp"
#include "stock.hpp"

#include <iostream>
#include <sstream>

Stock::Stock(std::time_t date, double price, double high, double low, double close){
	this->date = date;
	this->open = price;
	this->high = high;
	this->low = low;
	this->close = close;
}

Stock::Stock(std::string date, double price, double high, double low, double close){
	this->date = dateToEpoch(date.c_str());
	this->open = price;
	this->high = high;
	this->low = low;
	this->close = close;
}

Stock::Stock(std::time_t date, double price){
	this->date = date;
	this->open = price;
	this->high = price;
	this->low = price;
	this->close = price;
}

Stock::Stock(std::string date, double price){
	this->date = dateToEpoch(date.c_str());
	this->open = price;
	this->high = price;
	this->low = price;
	this->close = price;
}

Stock::~Stock() {}

std::time_t Stock::getDate(){
	return this->date;
}

std::string Stock::getDateToString(){
	return epochToDate(this->date);
}

double Stock::getOpen(){
	return this->open;
}

double Stock::getHigh(){
	return this->high;
}

double Stock::getLow(){
	return this->low;
}

double Stock::getClose(){
	return this->close;
}

std::string Stock::toString(){
	std::ostringstream osOpen;
	osOpen << this->open;

	std::ostringstream osHigh;
	osHigh << this->high;

	std::ostringstream osClose;
	osClose << this->close;

	std::ostringstream osLow;
	osLow << this->low;

	return "{ date : " + this->getDateToString() + " open : " + osOpen.str() + " high : " + osHigh.str() + " low : " + osLow.str() + " close : " + osClose.str() +" }";
}

void Stock::printStock(){
	std::cout << this->toString() << std::endl;
}
