#include "AForm.hpp"

AForm::AForm()
:
_name("form name"),
_signed(false),
_signGrade(1),
_execGrade(1)
{
	std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(const std::string name, bool stat, unsigned int signGrade, unsigned int execGrade)
:
_name(name),
_signed(stat),
_signGrade(signGrade),
_execGrade(execGrade)
{
	std::cout << "AForm constructor called." << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm& copy)
:
_name(copy.getName()),
_signed(copy.getStat()),
_signGrade(copy.getSignGrade()),
_execGrade(copy.getExecGrade())
{
	std::cout << "AForm copy constructor called." << std::endl;
	unsigned int signGrade = copy.getSignGrade();
	unsigned int execGrade = copy.getExecGrade();

	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}


AForm&	AForm::operator=(AForm& copy)
{
	std::cout << "AForm copy assign constructor called." << std::endl;
	unsigned int signGrade = copy.getSignGrade();
	unsigned int execGrade = copy.getExecGrade();

	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signed = copy.getStat();
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called." << std::endl;
}

const std::string	AForm::getName(void) const
{
	return _name;
}

bool	AForm::getStat(void) const
{
	return _signed;
}

unsigned int	AForm::getSignGrade(void) const
{
	return _signGrade;
}

unsigned int 	AForm::getExecGrade(void) const
{
	return _execGrade;
}

std::ostream&	operator<<(std::ostream& stream, AForm& form)
{
	stream << form.getName() << ", signed: " << form.getStat() << ", signing Grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ".";
	return stream;
}

void	AForm::beSigned(Bureaucrat const & b)
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
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (_signed == false)
		throw FormNotSigned();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowToExecute();
	action();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "This need to be signed!";
}

const char* AForm::GradeTooLowToExecute::what() const throw()
{
	return "Bureaucrat grade is to low to execute this form.";
}
