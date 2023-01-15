#include "Convertor.hpp"

Convertor::Convertor(std::string const & representation)
:
_representation(representation)
{
	std::cout << "Convertor Default constructor called." << std::endl;
}

Convertor::Convertor(Convertor& copy)
{
	(void)copy;
	std::cout << "Convertor copy constructor called." << std::endl;
}

Convertor&	Convertor::operator=(Convertor& copy)
{
	std::cout << "Convertor copy assign constructor called." << std::endl;
	return *this;
}

Convertor::~Convertor()
{
	std::cout << "Convertor destructor called." << std::endl;
}

bool	Convertor::isValid(void)
{
	unsigned int len = _representation.length();
	if (len == 0 || )
}
