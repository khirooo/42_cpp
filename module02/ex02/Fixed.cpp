#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
:
_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	_value = i << _bPoint;
}

Fixed::Fixed(const float i) //try without rounding
{
	std::cout << "Float constructor called" << std::endl;
	float	fvalue = i *  (1 << _bPoint);
	_value = roundf(fvalue);
}

Fixed::Fixed(const Fixed & num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed& Fixed::operator= (const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = num._value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	float	f;

	f = float(_value & (int)(pow(2, _bPoint) - 1)) / (1 << _bPoint);
	f += float(_value >> _bPoint);
	return(f);
}

int	Fixed::toInt(void) const
{
	int	i;

	i = _value >> _bPoint;
	return(i);
}

std::ostream& operator<<(std::ostream& stream, const Fixed &num)
{
	stream << num.toFloat();
	return (stream);
}

bool	Fixed::operator< (const Fixed& num)
{
	if(_value < num._value)
		return (true);
	return (false);
}

bool	Fixed::operator> (const Fixed& num)
{
	if(_value > num._value)
		return (true);
	return (false);
}

bool	Fixed::operator<= (const Fixed& num)
{
	if(_value <= num._value)
		return (true);
	return (false);
}
bool	Fixed::operator>= (const Fixed& num)
{
	if(_value >= num._value)
		return (true);
	return (false);
}

bool	Fixed::operator== (const Fixed& num)
{
	if(_value == num._value)
		return (true);
	return (false);
}
bool	Fixed::operator!= (const Fixed& num)
{
	if(_value != num._value)
		return (true);
	return (false);
}

Fixed	Fixed::operator+ (const Fixed& num)
{
	Fixed	res;

	res.setRawBits(this->_value + num._value);
	return (res);
}

Fixed	Fixed::operator- (const Fixed& num)
{
	Fixed	res;

	res.setRawBits(this->_value - num._value);
	return (res);
}

Fixed	Fixed::operator* (const Fixed& num)
{
	Fixed	res;

	res.setRawBits((this->_value * num._value) >> _bPoint);
	return (res);
}

Fixed	Fixed::operator/ (const Fixed& num)
{
	Fixed	res;

	res.setRawBits(this->toFloat() / num.toFloat());
	return (res);
}

Fixed&	Fixed::operator++ (void)
{
	++_value;
	return (*this);
}

Fixed&	Fixed::operator-- (void)
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator++ (int)
{
	Fixed copy;

	copy = *this;
	++_value;
	return (copy);
}

Fixed	Fixed::operator-- (int)
{
	Fixed copy = *this;

	--_value;
	return (copy);
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}
