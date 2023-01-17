#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class	Array
{
	private:

		T*				_array;
		unsigned int 	_size;
	
	public:

		Array();
		Array(unsigned int n);
		Array(Array& copy);
		Array& operator=(Array& copy);
		~Array();
		T& operator[](unsigned int index) const;
		unsigned int size(void) const;
		T*			getArray(void) const;
};
#include "Array.tpp"
#endif