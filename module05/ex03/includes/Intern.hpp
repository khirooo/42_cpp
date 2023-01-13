#ifndef INTERN_HPP
#define	INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

public:
	Intern();
	Intern(Intern& copy);
	Intern&	operator=(Intern& copy);
	~Intern();

	AForm*	makeForm(std::string name, std::string target);
};


#endif