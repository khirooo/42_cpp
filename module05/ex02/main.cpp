#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << std::endl;
		Bureaucrat*	john = new Bureaucrat("john", 2);
		std::cout << std::endl;
		Bureaucrat* tam = new Bureaucrat("tam", 42);
		std::cout << std::endl;
		AForm* form1 = new ShrubberyCreationForm("form1");
		std::cout << std::endl;
		AForm* form2 = new RobotomyRequestForm("from2");
		std::cout << std::endl;
		AForm* form3 = new PresidentialPardonForm("form3");

		std::cout << "------------------------------------------------" << std::endl;
		std::cout << *john << std::endl;
		std::cout << *tam << std::endl;
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;

		std::cout << "------------------------------------------------" << std::endl;
		form1->beSigned(*john);
		form2->beSigned(*tam);
		form3->beSigned(*john);

		std::cout << "------------------------------------------------" << std::endl;
		form1->execute(*john);
		std::cout << std::endl;
		tam->executeFrom(*form2);
		std::cout << std::endl;
		form3->execute(*john);

		std::cout << "------------------------------------------------" << std::endl;
		delete(john);
		std::cout << std::endl;
		delete(tam);
		std::cout << std::endl;
		delete(form1);
		std::cout << std::endl;
		delete(form2);
		std::cout << std::endl;
		delete(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
