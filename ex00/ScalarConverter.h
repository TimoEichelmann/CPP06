#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>

class ScalarConverter {
public:

    ScalarConverter(const ScalarConverter& other);

    ScalarConverter& operator=(const ScalarConverter& other);

	~ScalarConverter();

	static void convert(std::string input);
private:
	ScalarConverter();
};

#endif // SCALARCONVERTER_H
