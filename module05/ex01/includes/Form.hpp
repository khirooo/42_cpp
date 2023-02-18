#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;

public:
	Form(const std::string name = "");
	Form(const std::string name, bool stat, const unsigned int signGrade, const unsigned int execGrade);
	Form(Form& copy);
	Form&	operator=(Form& copy);
	~Form();

	const std::string	getName(void);
	bool	getStat(void);
	unsigned int	getSignGrade(void);
	unsigned int	getExecGrade(void);


	class	GradeTooHighException: public std::exception
	{
		public:
		const char* what() const throw();
	};

	class	GradeTooLowException: public std::exception
	{
		public:
		const char* what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& stream, Form& form);

#endif