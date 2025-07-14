#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>


int main(void)
{
	Data *data = new Data;
	Data *deserialized_data;
	data->name = "42";
	data->age = 42;

	std::cout << "initial pointer name: " << data->name << "\ninitial pointer age: " << data->age <<  std::endl;
	std::cout << "initial pointer address: " << data <<  std::endl;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << "\nserialized data address: " << raw << std::endl;
	deserialized_data = Serializer::deserialize(raw);
	std::cout << "\ndeserialized pointer name: " << deserialized_data->name << "\ndeserialized pointer age: " << deserialized_data->age <<  std::endl;
	std::cout << "deserialized pointer address: " << deserialized_data <<  std::endl;
	delete data;
}