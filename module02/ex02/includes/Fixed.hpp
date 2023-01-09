#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	/* data */
	int	_value;
	static int const _bPoint = 8;
public:

	Fixed();
	Fixed(const int i);
	Fixed(const float i);
	Fixed(const Fixed & num);
	Fixed& operator= (const Fixed &num);

	bool	operator< (const Fixed& num);
	bool	operator> (const Fixed& num);
	bool	operator<= (const Fixed& num);
	bool	operator>= (const Fixed& num);
	bool	operator== (const Fixed& num);
	bool	operator!= (const Fixed& num);

	Fixed	operator+ (const Fixed& num);
	Fixed	operator- (const Fixed& num);
	Fixed	operator* (const Fixed& num);
	Fixed	operator/ (const Fixed& num);

	//pre-increment
	Fixed&	operator++(void);
	Fixed&	operator--(void);
	//post-increment
	Fixed	operator++(int);
	Fixed	operator--(int);

	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int	const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed& min(Fixed& num1, Fixed& num2);
	static Fixed& max(Fixed& num1, Fixed& num2);
	const static Fixed& min(const Fixed& num1, const Fixed& num2);
	const static Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<< (std::ostream& stream, const Fixed &num);
#endif