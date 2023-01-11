#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
:
_name(name),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& trap)
:
_name(trap.getName()),
_hitPoints(trap.getHit()),
_energyPoints(trap.getEnergy()),
_attackDamage(trap.getDamage())
{
	std::cout << "Copy Constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& trap)
{
	std::cout << "Copy Assign constructor." << std::endl;
	_name = trap.getName();
	_hitPoints = trap.getHit();
	_energyPoints = trap.getEnergy();
	_attackDamage = trap.getDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int ClapTrap::getHit(void) const
{
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergy(void) const
{
	return (_energyPoints);
}

unsigned int ClapTrap::getDamage(void) const
{
	return (_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}


void	ClapTrap::setHit(unsigned int points)
{
	_hitPoints = points;
}


void	ClapTrap::setEnergy(unsigned int points)
{
	_energyPoints = points;
}


void	ClapTrap::setDamage(unsigned int damage)
{
	_attackDamage = damage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << _name << " is attacking " << target << ", causing " << _attackDamage << " damage." << std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints > 0)
	{
		std::cout << _name << " is taking " << amount << " of damage." << std::endl;
		_hitPoints -= _hitPoints >= amount ? amount : _hitPoints;
		if (_hitPoints <= 0)
			std::cout << "damn! " << _name << " just went to coma..." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << _name << " is repairing himself with " << amount << " health points." << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}

std::ostream& operator<< (std::ostream& stream, ClapTrap& trap)
{
	stream << "Name: " << trap.getName() << ", Hit points: " << trap.getHit() << ", Energy points: " << trap.getEnergy() << ", Attack damage: " << trap.getDamage();
	return (stream);
}
