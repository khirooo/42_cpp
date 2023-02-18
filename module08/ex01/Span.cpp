#include "Span.hpp"

Span::Span()
:
_size(0)
{
}

Span::Span(unsigned int size)
:
_size(size)
{
}

Span::Span(const Span& copy)
:
_size(copy._size)
{
	_spans.clear();
	_spans = copy._spans;
}

Span&	Span::operator=(Span& copy)
{
	if (copy._size > _size)
		throw NotEnoughSpaceLeftException();
	_spans.clear();
	_spans = copy._spans;
	return *this;
}

Span::~Span()
{
}

unsigned int	Span::getSize(void) const
{
	return _size;
}

std::vector<int> Span::getSpans(void) const
{
	return _spans;
}

void	Span::addNumber(int num)
{
	if (_spans.size() == _size)
		throw Span::SpanFullException();
	_spans.push_back(num);
}

int	Span::shortestSpan(void) const
{
	if (_spans.size() < 2)
		throw Span::NoSpanFoundException();
	std::vector<int>	copy = _spans;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator	it = copy.begin();
	int shortest_span = std::abs(*(it + 1) - *it);
	it++;
	while (it + 1 != copy.end())
	{
		if (std::abs(*(it + 1) - *it) < shortest_span)
			shortest_span =  std::abs(*(it + 1) - *it);
		it++;
	}
	return shortest_span;
}

int	Span::longestSpan(void) const
{
	if (_spans.size() < 2)
		throw Span::NoSpanFoundException();
	std::vector<const int>::iterator	min = std::min_element(_spans.begin(), _spans.end());
	std::vector<const int>::iterator	max = std::max_element(_spans.begin(), _spans.end());
	return std::abs(*max - *min);
}

const char*	Span::SpanFullException::what() const throw()
{
	return ("Span full can't add more.");
}

const char*	Span::NoSpanFoundException::what() const throw()
{
	return "No span can be found!";
}

const char*	Span::NotEnoughSpaceLeftException::what() const throw()
{
	return  "Not enough space left";
}

std::ostream&	operator<<(std::ostream& out, Span& sp)
{
	std::vector<int>	spans = sp.getSpans();
	for(unsigned long i = 0; i < spans.size(); i++)
		out << spans[i] << " ";
	out << std::endl;
	return out;
}
