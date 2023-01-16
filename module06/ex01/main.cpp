#include <iostream>
#include <sstream>

typedef	struct s_Data
{
	std::string	string_data;
	int			int_data;
}	Data;

std::ostream&	operator<<(std::ostream& stream, Data& data)
{
	stream << "string data: " << data.string_data << ", int data: " << data.int_data << std::endl;
	return stream;
}

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main(void)
{
	Data	data = {"hello", 42};
	std::cout << *deserialize(serialize(&data));
	std::cout << &data << std::endl;
	std::cout << deserialize(serialize(&data)) << std::endl;
	return 0;
}