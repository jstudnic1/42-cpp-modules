#include "ScalarConverter.hpp"
#include "LiteralUtils.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = TYPE_INVALID;
	double value = 0.0;
	std::string pseudo;

	if (isCharLiteral(literal, value))
		type = TYPE_CHAR;
	else if (isPseudoFloat(literal, value, pseudo))
		type = TYPE_PSEUDO_FLOAT;
	else if (isPseudoDouble(literal, value, pseudo))
		type = TYPE_PSEUDO_DOUBLE;
	else if (isFloatLiteral(literal, value))
		type = TYPE_FLOAT;
	else if (isIntLiteral(literal, value))
		type = TYPE_INT;
	else if (isDoubleLiteral(literal, value))
		type = TYPE_DOUBLE;
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (type == TYPE_PSEUDO_FLOAT || type == TYPE_PSEUDO_DOUBLE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		printChar(value);
		printInt(value);
	}

	printFloat(type, value, pseudo);
	printDouble(type, value, pseudo);
}
