#include "../inc/ScalarConverter.h"



ScalarConverter::ScalarConverter()
{
	//Default Constructor
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	//Copy Constructor
	(void)other; // To avoid unused parameter warning
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	//Copy Assignment Constructor
	if (this != &other)
	{
		// Copy the contents of 'other' to 'this'
		// Since this class has no member variables, nothing to copy
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	//Destructor
}

Type determine_type(const std::string& input)
{
	if ((input.length() == 1 && (input[0] <= 56 || input[0] >= 7)) || (input.length() == 3 && input[0] == '\'' && input[2] == '\'' && (input[1] <= 56 || input[1] >= 7)))
		return CHAR;
	if (input == "nan" || input == "inf" || input == "-inf")
		return DOUBLE;
	if (input == "nanf" || input == "inff" || input == "-inff")
		return FLOAT;
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-' && input[i] != '+')
			return UNDEFINED;
	}
	if (input.find('.') == std::string::npos && input.find('f') == std::string::npos)
		return INT;
	if (input.find('.') != std::string::npos && input.find('f') == std::string::npos)
		return DOUBLE;
	if (input.find('.') != std::string::npos && input.find('f') != std::string::npos)
		return FLOAT;
	return UNDEFINED;
}

void ScalarConverter::convert(std::string input)
{
	Type type = determine_type(input);
	ScalarValue value;
	std::string error = "not printable";
	switch(type)
	{
		case CHAR:
			value.c = input.length() == 3 ? input[1] : input[0];
			if (value.c >= 32 && value.c <= 126)
				std::cout << "char: '" << value.c << "'" << std::endl;
			else
				std::cout << "char: " << error << std::endl;
			std::cout << "int: " << static_cast<int>(value.c) << std::endl;
			std::cout << "float: " << static_cast<float>(value.c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(value.c) << std::endl;
			break;
		case INT:
			value.i = atoi(input.c_str());
			if (value.i > 127)
				error = "impossible";
			std::cout << "int: " << value.i << std::endl;
			if (value.i >= 32 && value.i <= 126)
				std::cout << "char: '" << static_cast<char>(value.i) << "'" << std::endl;
			else
				std::cout << "char: " << error << std::endl;
			std::cout << "float: " << static_cast<float>(value.i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(value.i) << std::endl;
			break;
		case FLOAT:
			error = "impossible";
			if (input == "nanf")
				value.f = nanf("");
			else if (input == "inff")
				value.f = std::numeric_limits<float>::infinity();
			else if (input == "-inff")
				value.f = -std::numeric_limits<float>::infinity();
			else
			{
				value.f = atof(input.c_str());
				if (value.f <= 127)
					error = "not printable";
			}
			std::cout << "float: " << value.f << "f" << std::endl;
			if (value.f >= 32 && value.f <= 126)
				std::cout << "char: '" << static_cast<char>(value.f) << "'" << std::endl;
			else
				std::cout << "char: " << error << std::endl;
			if (error == "impossible")
				std::cout << "int: " << error << std::endl;
			else
				std::cout << "int: " << static_cast<int>(value.f) << std::endl;
			std::cout << "double: " << static_cast<double>(value.f) << std::endl;
			break;
		case DOUBLE:
			error = "impossible";
			if (input == "nan")
				value.d = nan("");
			else if (input == "inf")
				value.d = std::numeric_limits<double>::infinity();
			else if (input == "-inf")
				value.d = -std::numeric_limits<double>::infinity();
			else
			{
				value.d = strtod(input.c_str(), NULL);
				if (value.d <= 127)
					error = "not printable";
			}
			std::cout << "double: " << value.d << std::endl;
			if (value.d >= 32 && value.d <= 126)
				std::cout << "char: '" << static_cast<char>(value.d) << "'" << std::endl;
			else
				std::cout << "char: " << error << std::endl;
			if (error == "impossible")
				std::cout << "int: " << error << std::endl;
			else
				std::cout << "int: " << static_cast<int>(value.d) << std::endl;
			std::cout << "float: " << static_cast<float>(value.d) << "f" << std::endl;
			break;
		case UNDEFINED:
			std::cout << "Invalid input: " << input << std::endl;
			break;			
	}
}

