#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:

	FragTrap(std::string name);
	FragTrap(FragTrap& trap);
	FragTrap& operator=(FragTrap& trap);
	~FragTrap();

	void	highFivesGuys(void);
};

#endif