#include <iostream>
#include "Zombie.hpp"

#define nb 5

int	main(void)
{
	Zombie *horde = zombieHorde(nb, "jack");
	if (horde == NULL)
		return 1;
	for(int i = 0; i < nb; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
