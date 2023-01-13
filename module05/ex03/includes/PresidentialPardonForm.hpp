#ifndef PRESIDENTIALFORM_HPP
#define PRESIDENTIALFORM_HPP


#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm
{
private:
	/* data */
	std::string	_target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(PresidentialPardonForm& copy);
	~PresidentialPardonForm();

	std::string	getTarget();
	void	action(void) const;
};

#endif