#ifndef LITERALUTILS_HPP
#define LITERALUTILS_HPP

#include <string>
#include <limits>

enum LiteralType
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDO_FLOAT,
	TYPE_PSEUDO_DOUBLE,
	TYPE_INVALID
};

bool isCharLiteral(const std::string& s, double& value);
bool isPseudoFloat(const std::string& s, double& value, std::string& pseudo);
bool isPseudoDouble(const std::string& s, double& value, std::string& pseudo);
bool isFloatLiteral(const std::string& s, double& value);
bool isDoubleLiteral(const std::string& s, double& value);
bool isIntLiteral(const std::string& s, double& value);

void printChar(double value);
void printInt(double value);
void printFloat(LiteralType type, double value, const std::string& pseudo);
void printDouble(LiteralType type, double value, const std::string& pseudo);

#endif
