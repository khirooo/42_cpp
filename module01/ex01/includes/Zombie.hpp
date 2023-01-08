#include <string>

class Zombie
{
private:
	std::string	_name;
public:

	void	announce(void);
	void	setName(std::string name);
	Zombie();
	Zombie(std::string name);
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name);