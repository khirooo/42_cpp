
#include "Cat.hpp"
#include "Dog.hpp"

#define nb_zoo 4

int	main(void)
{
	Animal *zoo[nb_zoo];

	for(int i = 0; i < nb_zoo; i++)
	{
		if (i % 2)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
		std::cout << std::endl;
	}

	for(int i = 0; i < nb_zoo; i++)
	{
		delete(zoo[i]);
		std::cout << std::endl;
	}
	return (0);
}

// int main()
// {
// 	Cat* cat1 = new Cat();
// 	Cat* cat2 = new Cat(*cat1);
// 	Brain*	brain1 = cat1->getBrain();
// 	Brain*	brain2 = cat2->getBrain();

// 	brain1->setIdea(0, "lets throw a party");
// 	std::cout << std::endl;
// 	std::cout << "cat1 first idea " << brain1->getIdea(0) << std::endl;
// 	std::cout << "cat2 first idea " << brain2->getIdea(0) << std::endl;
// 	std::cout << std::endl;
// 	delete cat1;
// 	delete cat2;
// }
