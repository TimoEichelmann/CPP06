#include "../inc/Serializer.hpp"

Serializer::Serializer()
{
	//Default Constructor
}

Serializer::Serializer(const Serializer& other)
{
	//Copy Constructor
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
	{
		// Copy the contents of 'other' to 'this'
		// Since this class has no member variables, nothing to copy
	}
	return (*this);
}

Serializer::~Serializer()
{
	//Destructor
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *result = reinterpret_cast<Data *>(raw);
	return (result);
}

