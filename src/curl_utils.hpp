#ifndef CURL_UTILS_HPP
#define CURL_UTILS_HPP

#include <string>

/**
* @breif Write callback function for Curl
* @parem contents Deliever content pointer
* @parem size Content element byte size
* @parem nmemb Number of content element
* @parem userdata user data where contents are stored
* @return Real buffer size = size * nmemb
*/
size_t writeCallback(char *contents, size_t size, size_t nmemb, void *userdata);

/**
* @breif Parse the historical data
* @parem symbol stock symbol
**/
void getHistoricalData(std::string);
#endif
