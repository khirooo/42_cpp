#ifndef SHRUBBERYFORM_HPP
#define SHRUBBERYFORM_HPP


#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
	/* data */
	std::string	_target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& copy);
	~ShrubberyCreationForm();

	std::string	getTarget();
	void	action(void) const;
};

#endif