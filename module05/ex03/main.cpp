#include "Bureaucrat.hpp"
#include "Intern.hpp"


int	main(void)
{
	try
	{
		Intern* newbie = new Intern();
	
		AForm* form = newbie->makeForm("shrubbery creation", "target");
		if (form)
		{
			std::cout << *form << std::endl;
			form->action();
			delete(form);
		}
		delete(newbie);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
