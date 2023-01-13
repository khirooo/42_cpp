#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <exception>

class Bureaucrat
{
private:
	/* data */
	const std::string	_name;
	unsigned int		_grade;
public:
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat& copy);
	Bureaucrat&	operator=(Bureaucrat& copy);
	~Bureaucrat();

	const std::string	getName(void);
	unsigned int		getGrade(void);

	void	levelUp(void);
	void	levelDown(void);
	
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

std::ostream&	operator<<(std::ostream& stream, Bureaucrat& b);
#endif