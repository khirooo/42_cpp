#include "Animal.hpp"

Animal::Animal()
:
_type("animal")
{
	std::cout << "Default animal constructor called." << std::endl; 
}

Animal::Animal(Animal& animal)
:
_type(animal.getType())
{
	std::cout << "Animal copy constructor called." << std::endl; 
}

Animal&	Animal::operator=(Animal& animal)
{
	std::cout << "Animal copy assign constructor called." << std::endl; 
	_type = animal.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Default animal Destructor called." << std::endl; 
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
