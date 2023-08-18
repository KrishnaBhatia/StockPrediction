#ifndef LISTING_H
#define LISTING_H

#include "stock.hpp"

#include <vector>

/**
 * @breif listing class
 **/

class Listing{

public:
	/**
	* @brief lisitng constructor
	* @parem symbol
	**/
	Listing(std::string symbol);

	/**
	* @breif listing destructor
	**/
	~Listing();

	/**
	* @breif stocks number
	* @return number of stocks in the listing
	**/
	size_t nbStocks();

	/**
	* @breif stock getter by inde
	* @parem i stock index
	* @return stock(i);
	**/
	Stock getStock(size_t i);

	/**
	* @breif stock getter by date
	* @parem date stock date
	* @return stock(date)
	**/
	Stock getStock(std::time_t date);

	/**
	* @brief stock getter by ate
	* @parem date stock date
	* @return stock(date)
	**/
	Stock getStock(std::string date);

	/**
	* @brief print all the stocks
	**/
	void printStocks();

	/**
	* @brief clear all the stocks
	**/
	void clearStocks();

	/**
	* @brief fill stocks vector on a period
	* @parem period1 begining date (POSIX timestamp)
	* @parem period2 ending date (POSIX timestamp)
	* @parem interval date interval for stocks, examples
	* 	daily "1d"
	*	weekly "1w"
	*	annula "1y"
	* @return string containing historical data
	**/
	std::string getHistoricalStocks(std::time_t period1, std::time_t period2, const char *interval);

	
	/**
        * @brief fill stocks vector on a period
        * @parem period1 begining date (POSIX timestamp)
        * @parem period2 ending date (POSIX timestamp)
        * @parem interval date interval for stocks, examples
        *       daily "1d"
        *       weekly "1w"
        *       annualy "1y"
        **/
	void getHistoricalStock(std::time_t period1, std::time_t period2, const char *interval);

	/**
        * @brief fill stocks vector on a period
        * @parem period1 begining date (format yyyy-mm-dd)
        * @parem period2 ending date (format yyyy-mm-dd)
        * @parem interval date interval for stocks, examples
        *       daily "1d"
        *       weekly "1w"
        *       annually "1y"
        **/
	void getHistoricalStock(const char *period1, const char *period2, const char *interval);

private:

	/**
	* @brief stock symbol
	**/
	std::string symbol;

	/**
	* @brief stocks vector
	**/
	std::vector<Stock> stocks;
};

#endif
