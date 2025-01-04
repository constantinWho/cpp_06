#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>

class ScalarConverter {
public:
	static void			convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();

	static bool			isChar(const std::string &literal);
	static bool			isInt(const std::string &literal);
	static bool			isFloat(const std::string &literal);
	static bool			isDouble(const std::string &literal);
	static bool			isInfinite(const std::string &literal);

	static void			convertFromChar(const std::string &literal);
	static void			convertToNumber(const std::string &literal, long double number);
	static void			convertFromInfinite(const std::string &literal);
	static void			convertToChar(char c);
};

#endif // SCALARCONVERTER_HPP
