#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat& WrongCat)
:
WrongAnimal(WrongCat)
{
	std::cout << "WrongCat copy constructor called." << std::endl; 
}

WrongCat&	WrongCat::operator=(WrongCat& WrongCat)
{
	std::cout << "WrongCat copy assign constructor called." << std::endl; 
	WrongAnimal::operator=(WrongCat);
	return (WrongCat);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

