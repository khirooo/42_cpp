#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:

	Brain*	_brain;
public:
	Cat();
	Cat(Cat& cat);
	Cat& operator=(Cat& cat);
	~Cat();

	void	makeSound(void) const;

	Brain*	getBrain(void) const;
};

#endif