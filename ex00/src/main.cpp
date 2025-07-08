#include "../inc/ScalarConverter.h"

int main(void)
{
	std::string input = "42.0f"; // Example input, you can change this to test different cases
	std::cout << "\033[31m" << "input: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input);
	input = "42"; // Another example input
	std::cout << "\033[31m" << "\ninput: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input);
	input = "42.7"; // Another example input
	std::cout << "\033[31m" << "\ninput: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input);
	input = "f";
	std::cout << "\033[31m" << "\ninput: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input);
	input = "nanf"; // Another example input
	std::cout << "\033[31m" << "\ninput: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input);
	input = "-inf"; // Another example input
	std::cout << "\033[31m" << "\ninput: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input);
	input = "iwef";
	std::cout << "\033[31m" << "\ninput: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input); // Invalid input
	input = "10000";
	std::cout << "\033[31m" << "\ninput: " << input << "\033[37m" << std::endl;
	ScalarConverter::convert(input); // Invalid input
}