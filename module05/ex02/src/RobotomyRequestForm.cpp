#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:
AForm("Robot Request", false, 72, 45)
{
	_target = target;
	std::cout << "RobotForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy)
:
AForm(copy)
{
	_target = copy.getTarget();
	std::cout << "RobotForm copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm& copy)
{
	std::cout << "RobotForm copy assign constructor called" << std::endl;
	AForm::operator=(copy);
	_target = copy.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotForm destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget()
{
	return _target;
}

void	RobotomyRequestForm::action(void) const
{
	std::cout << "DDDDRRRRRR!!!!" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomizing " << _target << " has failed" << std::endl;
}	
