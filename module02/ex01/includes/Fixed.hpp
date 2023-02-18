#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{

private:

	int	_value;
	static int const _bPoint = 8;

public:

	Fixed();
	Fixed(const int i);
	Fixed(const float i);
	Fixed(const Fixed & num);
	Fixed& operator= (const Fixed &num);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int	const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<< (std::ostream& stream, const Fixed &num);
#endif