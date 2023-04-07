#ifndef RNP_HPP
#define RNP_HPP
#include <iostream>
#include <sstream>
#include <stack>
#include <exception>

class RPN
{
private:
	std::string	expression_;
public:
	RPN(std::string exp = "");//default
	RPN(RPN const & copy);
	RPN& operator=(const RPN& copy);
	~RPN();

	void	solve(void) const;

	class InvalidInput: public std::exception
	{
		const char* what() const throw();
	};
};




#endif