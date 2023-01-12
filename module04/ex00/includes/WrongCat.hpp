#ifndef WRONGWrongCat_HPP
#define WRONGWrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat();
	WrongCat(WrongCat& wrongCat);
	WrongCat& operator=(WrongCat& wrongCat);
	~WrongCat();

	void	makeSound(void) const;
};

#endif