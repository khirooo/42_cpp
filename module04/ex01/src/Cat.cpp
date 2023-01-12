#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called." << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat& cat)
:
Animal(cat)
{
	std::cout << "Cat copy constructor called." << std::endl;
	_brain = new Brain(*(cat.getBrain()));
}

Cat&	Cat::operator=(Cat& cat)
{
	std::cout << "Cat copy assign constructor called." << std::endl; 
	Animal::operator=(cat);
	_brain = new Brain(*(cat.getBrain()));
	return (cat);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete(_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain*	Cat::getBrain(void)
{
	return _brain;
}
