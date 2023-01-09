#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	/* data */
	int	_value;
	static int const _bPoint = 8;
public:

	Fixed();
	Fixed(const Fixed & num);
	Fixed& operator= (const Fixed &num);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int	const raw);
};


#endif