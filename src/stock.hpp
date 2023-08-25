#ifndef STOCK_HPP
#define STOCK_HPP

#include <string>
#include <ctime>

/**
* @brief stock class
**/
class Stock{

	public:

		/**
		* @brief stock constructor
		* @parem date  stock date
		* @parem open price at opening
		* @parem high highest price value
		* @parem low lowest price value
		* @parem close price at closing
		**/
		Stock(std::time_t date, double open, double high, double low, double close);

		/**
		* @brief stock constructor
		* @parem date stock date
		* @parem open price at opening
		* @parem high highest price value
		* @parem low lowest price value
		* @parem close price at closing
		**/
		Stock(std::string date, double open, double high, double low, double close);

		/**
		* @brief stock condstructor
		* @parem date stock date
		* @parem price price at closing
		**/
		Stock(std::time_t date, double price);

		/**
		* @brief stock constructor
		* @parem date stock date
		* @parem price price at closing
		*/
		Stock(std::string date, double price);
	
		/**
		* @breif stock destructor
		**/
		~Stock();
		
		/**
		* @brief date getter
		* @return stock date
		**/
		std::time_t getDate();

		/**
		* @brief date getter
		* @return stock date
		**/
		std::string getDateToString();

		/**
		* @brief open price getter
		* @return opening price
		**/
		double getOpen();

		/**
		* @brief highest price getter
		* @return highest price
		**/
		double getHigh();

		/**
		* @brief lowest price getter
		* @return lowest price
		**/
		double getLow();

		/**
		* @brief closing price getter
		* @return closing price
		**/
		double getClose();
	
		/**
		* @brief convert stock to string
		* @return string containing the stock info
		**/
		std::string toString();
	
		/**
		* @brief print the stocks
		**/
		void printStock();

	private:
	
		/**
		* @brief srock date in epoch format
		**/
		std::time_t date;

		/**
		* @brief price at opening
		**/
		double open;

		/**
		* @brief highest price value at this date
		**/
		double high;

		/**
		* @brief lowest price at this date
		**/
		double low;

		/**
		* @brief closing price at this date
		**/
		double close;
};
#endif
