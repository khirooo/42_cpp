#include "Form.hpp"

Form::Form(const std::string name)
:
_name(name),
_signed(false),
_signGrade(1),
_execGrade(1)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string name, bool stat, unsigned int signGrade, unsigned int execGrade)
:
_name(name),
_signed(stat),
_signGrade(signGrade),
_execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form& copy)
:
_name(copy.getName()),
_signed(copy.getStat()),
_signGrade(copy.getSignGrade()),
_execGrade(copy.getExecGrade())
{
	std::cout << "Form copy constructor called." << std::endl;
	unsigned int signGrade = copy.getSignGrade();
	unsigned int execGrade = copy.getExecGrade();

	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}


Form&	Form::operator=(Form& copy)
{
	std::cout << "Form copy assign constructor called." << std::endl;
	unsigned int signGrade = copy.getSignGrade();
	unsigned int execGrade = copy.getExecGrade();

	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signed = copy.getStat();
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

const std::string	Form::getName(void)
{
	return _name;
}

bool	Form::getStat(void)
{
	return _signed;
}

const unsigned int	Form::getSignGrade(void)
{
	return _signGrade;
}

const unsigned int 	Form::getExecGrade(void)
{
	return _execGrade;
}

std::ostream&	operator<<(std::ostream& stream, Form& form)
{
	stream << form.getName() << ", signed: " << form.getStat() << ", signing Grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ".";
	return stream;
}

void	Form::beSigned(Bureaucrat& b)
{
	unsigned int grade = b.getGrade();
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= _signGrade)
	{
		_signed = true;
		std::cout << b.getName() << "  signed " << _name << "." << std::endl;
	}
	else
		std::cout << b.getName() << " couldn't sign " << _name << " because his grade is to low (grade = " << b.getGrade() << ")" << std::endl;
}