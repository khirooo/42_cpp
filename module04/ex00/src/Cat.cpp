#include "Cat.hpp"

Cat::Cat() //Animal() is being implicitly called ;)
{
	_type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(Cat& cat)
:
Animal(cat)
{
	std::cout << "Cat copy constructor called." << std::endl; 
}

Cat&	Cat::operator=(Cat& cat)
{
	std::cout << "Cat copy assign operator called." << std::endl; 
	Animal::operator=(cat);
	return (cat);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

