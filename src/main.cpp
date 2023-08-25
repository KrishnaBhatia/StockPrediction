#include <iostream>
#include "listing.hpp"

int main(){

	Listing *tsla = new Listing("TSLA");
	tsla->getHistoricalData("TSLA");
	//std::cout<<stockData;
	return 0;
}
