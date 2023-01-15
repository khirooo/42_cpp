#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <string>
#include <iostream>
#include <exception>

class Convertor
{
private:
	/* data */
	std::string const	_representation;
public:
	Convertor(std::string const &representation);
	Convertor(Convertor& copy);
	Convertor&	operator=(Convertor& copy);
	~Convertor();

	bool	isValid(void);

	class InvalidInput: public std::exception
	{
		const char * what() const throw()
		{
			return "Invalid input";
		}
	};
};

#endif