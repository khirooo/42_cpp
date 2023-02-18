#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	*b = new Bureaucrat("john", 2);
		std::cout << *b << std::endl;
		b->levelUp();
		std::cout << *b << std::endl;
		b->levelUp();
		std::cout << *b << std::endl;
		delete (b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
