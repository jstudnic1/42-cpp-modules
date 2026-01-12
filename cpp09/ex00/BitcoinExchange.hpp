#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	void run(const std::string &filename);
private:
	std::map<std::string, float> _data;
	void parseDatabase(const std::string &filename);
	float getExchangeRate(const std::string &date);
	bool isValidDate(const std::string &date);
	bool isValidValue(const std::string &value);
};
#endif
