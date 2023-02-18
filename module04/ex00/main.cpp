
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const WrongAnimal* wCat1 = new WrongCat();
	const WrongCat* wCat2 = new WrongCat();

	std::cout << std::endl;

	std::cout << "cat: " << cat->getType() << std::endl;
	std::cout << "dog: " << dog->getType() << std::endl;
	std::cout << "wCat1: " << wCat1->getType() << std::endl;
	std::cout << "wCat2: " << wCat2->getType() << std::endl << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	
	std::cout << std::endl;

	wCat1->makeSound();
	wCat2->makeSound();

	std::cout << std::endl;

	delete animal;
	delete cat;
	delete dog;

	std::cout << std::endl;

	delete wCat1;
	std::cout << std::endl;
	delete wCat2;

	return (0);
}
