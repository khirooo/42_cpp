#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <exception>

// template <typename T>
// int	easyfind(T& container, int n)
// {
// 	typename T::iterator	it1;
// 	typename T::iterator	it2 = container.end();

// 	for (it1 = container.begin(); it1 != it2; ++it1)
// 		if (*it1 == n)
// 			return (*it1);
// 	throw std::out_of_range("number not found");
// }

template <typename T>

typename T::iterator easyfind(T& container, int n)
{
	return (std::find(container.begin(), container.end(), n));
}

#endif