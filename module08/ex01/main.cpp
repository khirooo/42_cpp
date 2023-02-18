#include <iostream>
#include <array>
#include <ctime>
#include <algorithm>
#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::array<int, 10>	array = {1, 2, 3, 4, 5, 3, 67, 0, 12, -1};
		Span sp2(12);
		sp2.addNumber(6);
		sp2.addNumber(9);
		sp2.addNumbers(array.begin(), array.end());
		std::cout << sp2;

		Span sp3(10000);
		std::vector<int> v(10000);
		std::srand(unsigned(std::time(nullptr)));
		// Officialy this is a comment !
		// std::generate(v.begin(), v.end(), std::rand);
		// sp3.addNumbers(v.begin(), v.end());
		std::cout << sp3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
