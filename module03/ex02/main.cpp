#include "FragTrap.hpp"

int main()
{
	FragTrap john("John");
	ClapTrap jim("Jim");
	FragTrap joe("joe");

	joe = john;
	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << joe << std::endl;
	john.attack("Marge");
	john.attack("Bart");
	john.attack("Homer");
	std::cout << john << std::endl;
	john.takeDamage(5);
	std::cout << john << std::endl;
	jim.takeDamage(9);
	jim.takeDamage(10);
	std::cout << jim << std::endl;
	joe.beRepaired(10);
	joe.takeDamage(19);
	std::cout << joe << std::endl;
	joe.highFivesGuys();
	return (0);
}
