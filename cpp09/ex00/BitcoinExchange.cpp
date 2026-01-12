#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
	parseDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	this->_data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseDatabase(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	size_t commaPos;
	std::getline(file, line);
	while (std::getline(file, line)) {
		commaPos = line.find(',');
		std::string date = line.substr(0, commaPos);
		std::string rate = line.substr(commaPos + 1, line.length() - 1);
		_data[date] = std::atof(rate.c_str());
	}
	file.close();
}

float BitcoinExchange::getExchangeRate(const std::string &date) {
	if (_data.empty()) return 0.0f;

	std::map<std::string, float>::iterator it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
		return it->second;

	if (it == _data.begin())
		return 0.0f;
	it--;
	return it->second;
}

void BitcoinExchange::run(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        if (!date.empty() && date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);

        std::string valueStr = line.substr(pipePos + 1);
        if (!valueStr.empty() && valueStr[0] == ' ')
            valueStr.erase(0, 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isValidValue(valueStr)) {
            continue;
        }

        float rate = getExchangeRate(date);
        float value = static_cast<float>(std::atof(valueStr.c_str()));
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	// Validate that year, month, day portions are digits
	for (size_t i = 0; i < 4; i++)
		if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;
	for (size_t i = 5; i < 7; i++)
		if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;
	for (size_t i = 8; i < 10; i++)
		if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return false;

	if (month == 2) {
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29 : 28)) return false;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr) {
    char *end;
    double value = std::strtod(valueStr.c_str(), &end);

    if (valueStr.empty() || (end == valueStr.c_str()))
        return false;

	if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}
