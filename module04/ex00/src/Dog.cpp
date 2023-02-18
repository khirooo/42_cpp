#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(Dog& Dog)
:
Animal(Dog)
{
	std::cout << "Dog copy constructor called." << std::endl; 
}

Dog&	Dog::operator=(Dog& Dog)
{
	std::cout << "Dog copy assign operator called." << std::endl; 
	Animal::operator=(Dog);
	return (Dog);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}

