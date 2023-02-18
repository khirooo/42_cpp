#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
	_brain = new Brain();
}

Dog::Dog(Dog& dog)
:
Animal(dog)
{
	std::cout << "Dog copy constructor called." << std::endl; 
	_brain = new Brain(*(dog.getBrain()));
}

Dog&	Dog::operator=(Dog& dog)
{
	std::cout << "Dog copy assign operator called." << std::endl; 
	Animal::operator=(dog);
	_brain = new Brain(*(dog.getBrain()));
	return (dog);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete(_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return _brain;
}
