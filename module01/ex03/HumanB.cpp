#include "HumanB.hpp"

HumanB::HumanB(std::string name)
:
_name(name),
_weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (!_weapon)
		std::cout << _name << " attacks with their hands (old school)" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
