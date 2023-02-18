#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:
ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap& trap)
:
ClapTrap(trap)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap& trap)
{
	std::cout << "FragTrap copy Assign constructor called." << std::endl;
	ClapTrap::operator=(trap);
	return (trap);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " is requesting a couple of high fives." << std::endl;
}
