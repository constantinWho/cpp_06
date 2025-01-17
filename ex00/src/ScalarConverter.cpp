#include "../inc/ScalarConverter.hpp"
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

char	convertEscapeSequence(const std::string & literal) {
	struct EscapeSequence {
		const char *sequence;
		char value;
	};

	EscapeSequence escapeSequences[] = {
		{"\\n", '\n'},
		{"\\t", '\t'},
		{"\\r", '\r'},
		{"\\v", '\v'},
		{"\\f", '\f'},
		{"\\b", '\b'},
		{"\\0", '\0'}
	};
	for (int i = 0; i < 7; ++i) {
		if (literal == escapeSequences[i].sequence) {
			return escapeSequences[i].value;
		}
	}
	return '\0';
}

void	ScalarConverter::convert(const std::string &literal) {
	if (literal.empty()) {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}

	char escapedChar = convertEscapeSequence(literal);
	if (escapedChar != '\0') {
		convertFromChar(std::string(1, escapedChar));
		return;
	}

	if (isChar(literal)) {
		convertFromChar(literal);
	} else if (isInt(literal)) {
		convertToNumber(literal, std::strtold(literal.c_str(), NULL));
	} else if (isFloat(literal)) {
		convertToNumber(literal, std::strtold(literal.c_str(), NULL));
	} else if (isDouble(literal)) {
		convertToNumber(literal, std::strtold(literal.c_str(), NULL));
	} else if (isInfinite(literal)) {
		convertFromInfinite(literal);
	} else {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	}
}

bool ScalarConverter::isChar(const std::string &literal) {
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal) {
	size_t index = 0;
	if (literal[index] == '+' || literal[index] == '-') index++;
	return literal.find_first_not_of("0123456789", index) == std::string::npos;
}

bool ScalarConverter::isFloat(const std::string &literal) {
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;

	size_t index = 0;
	if (literal[index] == '+' || literal[index] == '-') index++;

	size_t dotPos = literal.find('.');
	if (dotPos == std::string::npos || literal[literal.length() - 1] != 'f') return false;

	std::string beforeDot = literal.substr(index, dotPos - index);
	std::string afterDot = literal.substr(dotPos + 1, literal.size() - dotPos - 2);

	return !beforeDot.empty() && !afterDot.empty() &&
		beforeDot.find_first_not_of("0123456789") == std::string::npos &&
		afterDot.find_first_not_of("0123456789") == std::string::npos;
}

bool ScalarConverter::isDouble(const std::string &literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;

	size_t index = 0;
	if (literal[index] == '+' || literal[index] == '-') index++;

	size_t dotPos = literal.find('.');
	if (dotPos == std::string::npos) return false;

	std::string beforeDot = literal.substr(index, dotPos - index);
	std::string afterDot = literal.substr(dotPos + 1);

	return !beforeDot.empty() && !afterDot.empty() &&
			beforeDot.find_first_not_of("0123456789") == std::string::npos &&
			afterDot.find_first_not_of("0123456789") == std::string::npos;
}

bool	ScalarConverter::isInfinite(const std::string &literal) {
	return literal == "-inf" || literal == "+inf" || literal == "nan" ||
		   literal == "-inff" || literal == "+inff" || literal == "nanf";
}

void ScalarConverter::convertFromChar(const std::string &literal) {
	char c = literal[0];
	convertToChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::convertToNumber(const std::string &literal, long double number) {
	(void)literal;

	if (std::isnan(number)) {
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
		return;
	}
	if (std::isinf(number)) {
		std::cout << "char: impossible\nint: impossible\n";
		std::cout << "float: " << (number > 0 ? "+inff" : "-inff") << "\n";
		std::cout << "double: " << (number > 0 ? "+inf" : "-inf") << "\n";
		return;
	}

	if (number < std::numeric_limits<char>::min() || number > std::numeric_limits<char>::max()) {
		std::cout << "char: impossible\n";
	} else {
		convertToChar(static_cast<char>(number));
	}

	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(number) << std::endl;
	}

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(number) << "f\n";
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void	ScalarConverter::convertToChar(char c) {
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void	ScalarConverter::convertFromInfinite(const std::string &literal) {
	std::cout << "char: impossible\nint: impossible\n";
	if (literal.find("nan") != std::string::npos) {
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	} else {
		std::cout << "float: " << literal[0] << "inff\n";
		std::cout << "double: " << literal[0] << "inf\n";
	}
}
