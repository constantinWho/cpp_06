#include "./inc/ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
	std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}

/* void testConversion(const std::string &literal) {
	std::cout << "Input: " << literal << std::endl;
	ScalarConverter::convert(literal);
	std::cout << "--------------------------------------" << std::endl;
}

int main() {
	// Test char inputs
	testConversion("a");
	testConversion("Z");
	testConversion("!");

	// Test non-displayable char
	testConversion("\n");
	testConversion("\t");
	testConversion("\b");

	// Test integer inputs
	testConversion("0");
	testConversion("42");
	testConversion("-42");
	testConversion("2147483647"); // INT_MAX
	testConversion("-2147483648"); // INT_MIN
	testConversion("2147483648"); // Overflow

	// Test float inputs
	testConversion("0.0f");
	testConversion("-4.2f");
	testConversion("4.2f");
	testConversion("42.0f");
	testConversion("-inff");
	testConversion("+inff");
	testConversion("nanf");

	// Test double inputs
	testConversion("0.0");
	testConversion("-4.2");
	testConversion("4.2");
	testConversion("42.0");
	testConversion("-inf");
	testConversion("+inf");
	testConversion("nan");

	// Test invalid inputs
	testConversion("abc");
	testConversion("42abc");
	testConversion("");
	testConversion("++42");
	testConversion("42.42.42");
	testConversion("nanx");

	return 0;
} */

