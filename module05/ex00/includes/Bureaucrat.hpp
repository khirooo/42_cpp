#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;

public:
	Bureaucrat(std::string name = "", unsigned int grade = 150);
	Bureaucrat(Bureaucrat& copy);
	Bureaucrat&	operator=(Bureaucrat& copy);
	~Bureaucrat();

	const std::string	getName(void) const;
	unsigned int		getGrade(void) const;

	void	levelUp(void);
	void	levelDown(void);
	
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

std::ostream&	operator<<(std::ostream& stream, Bureaucrat& b);
#endif