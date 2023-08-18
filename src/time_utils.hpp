#ifndef TIME_UTILS_HPP
#define TIME_UTILS_HPP

#include <string>
#include <ctime>

/**
* @breif cuurent epoch time (POSIX)
* @return the current POSIX time
**/
std::time_t currentEpoch();

/**
* @breif convert date to POSIX time
* @parem date date to convert to yyyy-mm-dd format (ignore hour)
* @return date in epoch format
**/
std::time_t dateToEpoch(const char *date);

/**
* @brief convert POSIX timestamp in date
* @parem epoch POSIX timestamp
* @return date in yyyy-mm-dd format (ignore hour)
**/
std::string epochToDate(const std::time_t  epoch);

#endif
