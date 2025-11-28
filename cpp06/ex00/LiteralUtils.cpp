#include "LiteralUtils.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <cctype>
#include <cmath>

namespace
{
	bool parseNumber(const std::string& s, double& out)
	{
		char* end = NULL;
		errno = 0;
		out = std::strtod(s.c_str(), &end);
		if (end == s.c_str())
			return false;
		if (*end != '\0')
			return false;
		if (errno == ERANGE)
			return false;
		return true;
	}

	std::string formatFloat(float value)
	{
		std::ostringstream oss;
		if (value == static_cast<long long>(value))
			oss << std::fixed << std::setprecision(1) << value;
		else
			oss << value;
		return oss.str();
	}

	std::string formatDouble(double value)
	{
		std::ostringstream oss;
		if (value == static_cast<long long>(value))
			oss << std::fixed << std::setprecision(1) << value;
		else
			oss << value;
		return oss.str();
	}
} // namespace

bool isCharLiteral(const std::string& s, double& value)
{
	if (s.size() == 1 && std::isprint(static_cast<unsigned char>(s[0])) &&
		!std::isdigit(static_cast<unsigned char>(s[0])))
	{
		value = static_cast<double>(s[0]);
		return true;
	}
	if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
	{
		value = static_cast<double>(s[1]);
		return true;
	}
	return false;
}

bool isPseudoFloat(const std::string& s, double& value, std::string& pseudo)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
	{
		pseudo = s;
		if (s[0] == '-')
			value = -std::numeric_limits<double>::infinity();
		else if (s[0] == '+')
			value = std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	return false;
}

bool isPseudoDouble(const std::string& s, double& value, std::string& pseudo)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
	{
		pseudo = s;
		if (s[0] == '-')
			value = -std::numeric_limits<double>::infinity();
		else if (s[0] == '+')
			value = std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	return false;
}

bool isFloatLiteral(const std::string& s, double& value)
{
	if (s.empty() || s[s.size() - 1] != 'f')
		return false;
	std::string core = s.substr(0, s.size() - 1);
	return parseNumber(core, value);
}

bool isDoubleLiteral(const std::string& s, double& value)
{
	return parseNumber(s, value);
}

bool isIntLiteral(const std::string& s, double& value)
{
	if (s.empty())
		return false;
	char* end = NULL;
	errno = 0;
	long val = std::strtol(s.c_str(), &end, 10);
	if (*end != '\0' || errno == ERANGE)
		return false;
	value = static_cast<double>(val);
	return true;
}

void printChar(double value)
{
	std::cout << "char: ";
	if (!std::isfinite(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void printInt(double value)
{
	std::cout << "int: ";
	if (!std::isfinite(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void printFloat(LiteralType type, double value, const std::string& pseudo)
{
	std::cout << "float: ";
	if (type == TYPE_PSEUDO_FLOAT)
	{
		std::cout << pseudo << std::endl;
		return;
	}
	if (type == TYPE_PSEUDO_DOUBLE)
	{
		std::cout << pseudo << "f" << std::endl;
		return;
	}
	if (!std::isfinite(value) ||
		value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	float f = static_cast<float>(value);
	std::cout << formatFloat(f) << "f" << std::endl;
}

void printDouble(LiteralType type, double value, const std::string& pseudo)
{
	std::cout << "double: ";
	if (type == TYPE_PSEUDO_FLOAT || type == TYPE_PSEUDO_DOUBLE)
	{
		if (pseudo == "nanf")
			std::cout << "nan" << std::endl;
		else if (pseudo == "+inff")
			std::cout << "+inf" << std::endl;
		else if (pseudo == "-inff")
			std::cout << "-inf" << std::endl;
		else
			std::cout << pseudo << std::endl;
		return;
	}
	if (!std::isfinite(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << formatDouble(value) << std::endl;
}
