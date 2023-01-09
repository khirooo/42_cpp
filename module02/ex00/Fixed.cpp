#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
:
_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed& Fixed::operator= (const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = num.getRawBits();
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
