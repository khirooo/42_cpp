#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	*b = new Bureaucrat("john", 149);
		std::cout << *b << std::endl;
		b->levelDown();
		std::cout << *b << std::endl;
		b->levelDown();
		std::cout << *b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
