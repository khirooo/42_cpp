#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <string>
#include <iostream>
#include <exception>

enum	type {Char, Int, Float, Double};

class Convertor
{
private:
	/* data */
	std::string const	_representation;
	type				_type;
	std::string			_values[4];
	int					_int_value;
	char				_char_value;
	float				_float_value;
	double				_double_value;

public:
	Convertor(std::string const &representation);
	Convertor(Convertor& copy);
	Convertor&	operator=(Convertor& copy);
	~Convertor();

	void	isValid(void) const;
	void	detect_convert(void);
	void	check_overflow(void) const;
	void	getCharValue(void);
	void	getIntValue(void);
	void	getFloatValue(void);
	void	getDoubleValue(void);
	void	print_values(void);

	class InvalidInput1: public std::exception
	{
		const char * what() const throw()
		{
			return "Invalid input impossible to convert to any type!";
		}
	};

	class InvalidInput2: public std::exception
	{
		const char * what() const throw()
		{
			return "Invalid input overflow when converting!";
		}
	};
};

#endif