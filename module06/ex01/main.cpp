#include <iostream>

#include "Serializer.hpp"

int	main(void)
{
	Data	data = {"hello", 42};
	std::cout << *Serializer::deserialize(Serializer::serialize(&data));
	std::cout << &data << std::endl;
	std::cout << Serializer::deserialize(Serializer::serialize(&data)) << std::endl;
	return 0;
}