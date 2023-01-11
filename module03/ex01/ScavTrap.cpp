#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& trap)
: ClapTrap(trap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(ScavTrap& trap)
{
	ClapTrap::operator=(trap);
	std::cout << "ScavTrap copy Assign constructor." << std::endl;
	return (trap);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " is attacking " << target << ", causing " << _attackDamage << " damage." << std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::gardeGate()
{
	std::cout << "We out there in gate keeper mode !" << std::endl;
}