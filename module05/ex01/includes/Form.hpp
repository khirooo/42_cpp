#ifndef FORM_HPP
#define FORM_HPP

#include <Bureaucrat.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <exception>

class Form
{
private:

	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;

public:
	Form(const std::string name);
	Form(const std::string name, bool stat, const unsigned int signGrade, const unsigned int execGrade);
	Form(Form& copy);
	Form&	operator=(Form& copy);
	~Form();

	const std::string	getName(void);
	bool	getStat(void);
	const unsigned int	getSignGrade(void);
	const unsigned int	getExecGrade(void);
	void	beSigned(Bureaucrat& b);


	class	GradeTooHighException: public std::exception
	{
		public:

		const char* what() const throw()
		{
			return "Grade too high";
		}
	};

	class	GradeTooLowException: public std::exception
	{
		public:

		const char* what() const throw()
		{
			return "Grade too low";
		}
	};

};

std::ostream&	operator<<(std::ostream& stream, Form& form);

#endif