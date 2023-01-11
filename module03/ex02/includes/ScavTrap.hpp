#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{

public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap& trap);
	ScavTrap& operator= (ScavTrap& trap);
	~ScavTrap();

	void	attack(const std::string& target);
	void	gardeGate();
};

#endif