#include "Span.hpp"

Span::Span(unsigned int size)
:
_size(size)
{
}

Span::Span(Span& copy)
:
_size(copy.getSize())
{
	_spans.clear();
	_spans = copy.getSpans();
}

Span::~Span()
{
}

const unsigned int	Span::getSize(void) const
{
	return _size;
}

std::vector<int> Span::getSpans(void) const
{
	return _spans;
}

void	Span::addNumber(int num)
{
	if (_spans.size() >= _size)
		throw Span::SpanFullException();
	_spans.push_back(num);
}

void	Span::shortestSpan(void) const
{
	if (_spans.size() < 2)
		throw Span::NoSpanFoundException();
	int	n1 = _span
}

void	Span::longestSpan(void) const
{

}