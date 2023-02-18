#ifndef ROBOTOMYFORM_HPP
#define ROBOTOMYFORM_HPP


#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;

public:
	RobotomyRequestForm(std::string target = "");
	RobotomyRequestForm(RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	std::string	getTarget() const;
	void	action(void) const;
};

#endif