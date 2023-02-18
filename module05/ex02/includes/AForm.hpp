#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:

	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;

public:
	AForm();
	AForm(const std::string name, bool stat, const unsigned int signGrade, const unsigned int execGrade);
	AForm(AForm& copy);
	AForm&	operator=(AForm& copy);
	virtual ~AForm();

	const std::string	getName(void) const;
	bool	getStat(void) const;
	unsigned int	getSignGrade(void) const;
	unsigned int	getExecGrade(void) const;
	void	beSigned(Bureaucrat const & b);
	virtual	void	action(void) const = 0;
	void	execute(Bureaucrat const & executor) const;

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

	class	FormNotSigned: public std::exception
	{
		const char* what() const throw();
	};

	class	GradeTooLowToExecute: public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, AForm& form);

#endif