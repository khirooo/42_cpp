#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <string>

class Span
{
private:
	/* data */
	const unsigned int		_size;
	std::vector<int>	_spans;
public:
	Span(unsigned int size);
	Span(Span& copy);
	~Span();

	void	addNumber(int num);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

	const unsigned int		getSize(void) const;
	std::vector<int>	getSpans(void) const;
	class	SpanFullException:public std::exception
	{
		const char* what() const throw
		{
			return ("There is already " + std::to_string(_size) + " in the span.");
		}
	};

	class	NoSpanFoundException:public std::exception
	{
		const char* what() const throw
		{
			return "No span can be found check the size!";
		}
	};
};


#endif