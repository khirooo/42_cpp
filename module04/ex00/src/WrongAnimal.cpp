#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:
_type("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called." << std::endl; 
}

WrongAnimal::WrongAnimal(WrongAnimal& WrongAnimal)
:
_type(WrongAnimal.getType())
{
	std::cout << "WrongAnimal copy constructor called." << std::endl; 
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal& WrongAnimal)
{
	std::cout << "WrongAnimal copy assign constructor called." << std::endl; 
	_type = WrongAnimal.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default WrongAnimal Destructor called." << std::endl; 
}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Breathing ..." << std::endl; 
}
