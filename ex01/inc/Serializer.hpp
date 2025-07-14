#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "Data.hpp"
#include <stdint.h>

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);

	static Data* deserialize(uintptr_t raw);

private:
    Serializer();

    Serializer(const Serializer& other);

    Serializer& operator=(const Serializer& other);

	~Serializer();
};

#endif // SERIALIZER_H
