#ifndef	WRONGWrongAnimal_HPP
#define WRONGWrongAnimal_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	/* data */
	std::string	_type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal& wrongAnimal);
	WrongAnimal& operator= (WrongAnimal& wrongAnimal);
	~WrongAnimal();

	//setter
	void	setType(std::string type);
	//getter
	std::string	getType(void) const;

	//functions
	void	makeSound(void) const;
};

#endif