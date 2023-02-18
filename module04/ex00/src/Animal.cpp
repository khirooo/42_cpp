#include "Animal.hpp"

Animal::Animal()
:
_type("animal")
{
	std::cout << "Default animal constructor called." << std::endl; 
}

Animal::Animal(Animal& animal)
:
_type(animal._type)
{
	std::cout << "Animal copy constructor called." << std::endl; 
}

Animal&	Animal::operator=(Animal& animal)
{
	std::cout << "Animal copy assign operator called." << std::endl; 
	_type = animal._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl; 
}

void	Animal::setType(std::string type)
{
	_type = type;
}

std::string Animal::getType(void) const
{
	return _type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Breathing ..." << std::endl; 
}
