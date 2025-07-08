#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <limits>
#include <cmath>

enum Type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		UNDEFINED
};

union ScalarValue {
	char c;
	int i;
	float f;
	double d;
};

class ScalarConverter {
public:
	static void convert(std::string input);
private:
	ScalarConverter();

	ScalarConverter(const ScalarConverter& other);

    ScalarConverter& operator=(const ScalarConverter& other);

	~ScalarConverter();
};

#endif // SCALARCONVERTER_H
