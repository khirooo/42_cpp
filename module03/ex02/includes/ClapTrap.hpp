#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap
{
protected:
	/* data */
	std::string _name;
	unsigned int			_hitPoints;
	unsigned int			_energyPoints;
	unsigned int			_attackDamage;

public:

	ClapTrap(std::string name);
	ClapTrap(ClapTrap& trap);
	ClapTrap& operator= (ClapTrap& trap);
	~ClapTrap();

	//geters
	std::string	getName(void) const;
	unsigned int			getHit(void) const;
	unsigned int			getEnergy(void) const;
	unsigned int			getDamage(void) const;

	//seters
	void	setName(std::string name);
	void	setHit(unsigned int points);
	void	setEnergy(unsigned int points);
	void	setDamage(unsigned int danage);

	//functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& stream, ClapTrap& trap);
#endif