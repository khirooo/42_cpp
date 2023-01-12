#ifndef	ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	/* data */
	std::string	_type;
public:
	Animal();
	Animal(Animal& animal);
	Animal& operator= (Animal& animal);
	virtual ~Animal();

	//setter
	void	setType(std::string type);
	//getter
	std::string	getType(void) const;

	//functions
	virtual void	makeSound(void) const = 0;
};

#endif