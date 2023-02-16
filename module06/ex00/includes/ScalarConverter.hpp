#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <string>
#include <iostream>
#include <exception>

enum	type {Char, Int, Float, Double};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter& copy);
	ScalarConverter&	operator=(ScalarConverter& copy);
	~ScalarConverter();
public:
	static std::string 		_representation;
	static type				_type;
	static std::string		_values[4];
	static int				_int_value;
	static char				_char_value;
	static float			_float_value;
	static double			_double_value;

	static void	isValid(void);
	static void	detect_convert(void);
	static void	check_overflow(void);
	static void	getCharValue(void);
	static void	getIntValue(void);
	static void	getFloatValue(void);
	static void	getDoubleValue(void);
	static void	convert(std::string representation);

	class InvalidInput1: public std::exception
	{
		const char * what() const throw();
	};

	class InvalidInput2: public std::exception
	{
		const char * what() const throw();
	};
};

#endif