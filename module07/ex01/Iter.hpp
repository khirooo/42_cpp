#ifndef	ITER_HPP
#define ITER_HPP

#include<iostream>

template <typename T>
void	iter(T* ptr, size_t length, void (*f)(T&))
{
	for(size_t i = 0; i < length; i++)
		f(*(ptr + i));
}

template <typename T>
void	print(T& t)
{
	std::cout << t << " ";
}

#endif