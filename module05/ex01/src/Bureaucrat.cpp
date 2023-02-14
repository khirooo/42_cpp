#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
:
_name(name)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& copy)
:
_name(copy.getName())
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	unsigned int grade = copy.getGrade();
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& copy)
{
	std::cout << "Bureaucrat copy assign operator called." << std::endl;
	unsigned int grade = copy.getGrade();
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return _name;
}

unsigned int		Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::levelUp(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::levelDown(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form& form) const
{
	if (_grade <= form.getSignGrade())
		form.beSigned(*this);
	else
		std::cout << _name << " could not sign '" << form.getName() << "' because his grade is too low (" << _grade << ")." << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (stream);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

