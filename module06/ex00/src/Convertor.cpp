#include "Convertor.hpp"
#include "stdlib.h"

Convertor::Convertor(std::string const & representation)
:
_representation(representation)
{
	std::cout << "Convertor Default constructor called." << std::endl;
	isValid();
}

Convertor::Convertor(Convertor& copy)
{
	(void)copy;
	std::cout << "Convertor copy constructor called." << std::endl;
}

Convertor&	Convertor::operator=(Convertor& copy)
{
	std::cout << "Convertor copy assign constructor called." << std::endl;
	return *this;
}

Convertor::~Convertor()
{
	std::cout << "Convertor destructor called." << std::endl;
}

bool	is_number(std::string s)
{
	bool	found_point = false;
	bool	found_f		=	false;

	int	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!std::isdigit(s[i]))
		return false;
	while (i < s.length())
	{
		if ((!std::isdigit(s[i]) && s[i] != '.' && s[i] != 'f')|| (s[i] == 'f' && found_f) || (s[i] == '.' && found_point))
			return (false);
		if (s[i] == 'f')
			found_f = true;
		if (s[i] == '.')
			found_point = true;
		i++;
	}
	return (true);
}

void	Convertor::isValid(void) const
{
	if (_representation.empty())
		throw InvalidInput1();
	if (_representation == "-inff" || _representation == "+inff" || _representation == "nanf"
	||	_representation == "-inf" || _representation == "+inf" || _representation == "nan"
	||  _representation.length() == 1 || is_number(_representation))
		return ;
	throw InvalidInput1();
}


void	Convertor::getCharValue(void)
{
	std::cout << "Actual Type: CHAR" << std::endl;
	_values[0] = std::to_string(_representation[0]);
	_values[1] = "Impossible";
	_values[2] = "Impossible";
	_values[3] = "Impossible";
}

void		Convertor::getIntValue(void)
{
	std::cout << "Actual Type: INT" << std::endl;
	_int_value = atoi(_representation.c_str());
	_values[1] = std::to_string(_int_value);
	_char_value = static_cast<char>(_int_value);
	if (std::isprint(_char_value))
		_values[0] = std::string(1, _char_value);
	else
		_values[0] = "Non displayable";
	_float_value = static_cast<float>(_int_value);
	_values[2] = std::to_string(_float_value);
	_double_value = static_cast<double>(_int_value);
	_values[3] = std::to_string(_double_value);
}

void	Convertor::getFloatValue(void) 
{
	std::cout << "Actual Type: FLOAT" << std::endl;
	_float_value = atoi(_representation.c_str());
	_values[2] = std::to_string(_float_value);
	_char_value = static_cast<char>(_float_value);
	if (std::isprint(_char_value))
		_values[0] = std::string(1, _char_value);
	else
		_values[0] = "Non displayable";
	_int_value = static_cast<int>(_float_value);
	_values[1] = std::to_string(_int_value);
	_double_value = static_cast<double>(_float_value);
	_values[3] = std::to_string(_double_value);
}

void	Convertor::getDoubleValue(void) 
{
	std::cout << "Actual Type: DOUBLE" << std::endl;
	_double_value = atoi(_representation.c_str());
	_values[3] = std::to_string(_double_value);
	_char_value = static_cast<char>(_double_value);
	if (std::isprint(_char_value))
		_values[0] = std::string(1, _char_value);
	else
		_values[0] = "Non displayable";
	_int_value = static_cast<int>(_double_value);
	_values[1] = std::to_string(_int_value);
	_float_value = static_cast<float>(_double_value);
	_values[2] = std::to_string(_float_value);
}

void	Convertor::check_overflow(void) const
{
	if (_type == Int)
	{
		std::string	s_value = std::string(_representation);
		if (_representation[0] == '+')
			s_value = std::string(_representation.substr(1));
		if (s_value != std::to_string(_int_value))
			throw InvalidInput2();
	}
	else if (_type == Float)
	{
		std::string	s_value;
		if (_representation[0] == '+')
			s_value = std::string(_representation.substr(1));
		else
			s_value = std::string(_representation.substr(0, _representation.length() - 2));
		if (s_value != std::to_string(_float_value))
			throw InvalidInput2();
	}
	else if (_type == Float)
	{
		std::string	s_value = std::string(_representation);
		if (_representation[0] == '+')
			s_value = std::string(_representation.substr(1, _representation.length()));
		if (s_value != std::to_string(_float_value))
			throw InvalidInput2();
	}
}

void	Convertor::detect_convert(void)
{
	if (_representation.length() == 1 && !std::isdigit(_representation[0]))
		_type = Char;
	int	i = 0;
	for (i = 0; i < _representation.length(); i++)
	{
		if (i == 0 && (_representation[i] == '+' || _representation[0] == '-'))
			continue;
		if (!std::isdigit(_representation[i]))
			break;
	}
	if (i == _representation.length())
		_type = Int;
	for (i = 0; i < _representation.length(); i++)
		if (_representation[i] == '.' || _representation == "-inf" || _representation == "+inf" || _representation == "nan")
			_type = Double;
	for (i = 0; i < _representation.length(); i++)
		if (_representation[i] == 'f' || _representation == "-inff" || _representation == "+inff" || _representation == "nanf")
			_type = Float;
	switch (_type)
	{
	case Char:
		getCharValue();
		break;
	case Int:
		getIntValue();
		break;
	case Float:
		getFloatValue();
		break;
	case Double:
		getDoubleValue();
		break;
	default:
		throw InvalidInput1();
		break;
	}
	check_overflow();
}

void	Convertor::print_values(void)
{
	detect_convert();
	std::cout << "char: " << _values[0] << std::endl;
	std::cout << "int: " << _values[1] << std::endl;
	std::cout << "float: " << _values[2] << std::endl;
	std::cout << "double: " << _values[3] << std::endl;
}
