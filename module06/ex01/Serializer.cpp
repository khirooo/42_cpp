#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer& copy)
{
	(void)copy;
}

Serializer&	Serializer::operator=(Serializer& copy)
{
	(void)copy;
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

std::ostream&	operator<<(std::ostream& stream, Data& data)
{
	stream << "string data: " << data.string_data << ", int data: " << data.int_data << std::endl;
	return stream;
}