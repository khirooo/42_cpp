#include "RPN.hpp"

static bool	check_input(char c)
{
	if (std::isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

RPN::RPN(std::string exp)
:
expression_(exp)
{
}

RPN::RPN(const RPN& copy)
:
expression_(copy.expression_)
{
}

RPN& RPN::operator=(const RPN& copy)
{
	expression_=copy.expression_;
	return (*this);
}

void	RPN::solve(void) const
{
	std::istringstream	ss(expression_);
	std::stack<double>	my_stack;
	int	count = 0;
	char op;
	double	result, op1, op2;
	while (!ss.fail())
	{
		ss >> op;
		if (ss.fail())
			break;
		count++;
		if (!check_input(op))
			throw InvalidInput();
		if (std::isdigit(op))
			my_stack.push((double)(op - '0'));
		else
		{
			if (my_stack.size() < 2)
				throw InvalidInput();
			op1 = my_stack.top();
			my_stack.pop();
			op2 = my_stack.top();
			my_stack.pop();
			if (op == '+')
				my_stack.push(op2 + op1);
			else if (op == '-')
				my_stack.push(op2 - op1);
			else if (op == '*')
				my_stack.push(op2 * op1);
			else if (op == '/')
				my_stack.push(op2 / op1);
		}
	}
	if (my_stack.size() != 1 || count < 3)
		throw InvalidInput();
	result = my_stack.top();
	my_stack.pop();
	if ((int) result == result)
		std::cout << (int)result << std::endl;
	else
		std::cout << result << std::endl;
}

RPN::~RPN()
{
}

const char* RPN::InvalidInput::what() const throw()
{
	return "Error";
}
