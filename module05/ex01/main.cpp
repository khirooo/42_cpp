#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main(void)
{
	try
	{
		Bureaucrat*	b = new Bureaucrat("john", 15);
		Form* form = new Form("testing", false, 15, 150);

		std::cout << std::endl;
		std::cout << *b << std::endl;
		std::cout << *form << std::endl;
		form->beSigned(*b);
		std::cout << *form << std::endl;
		b->levelDown();
		b->signForm(*form);
		std::cout << std::endl;

		delete(b);
		delete(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
