#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Array default costructor called" << std::endl;
	_array = new T[0]();
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array costructor array(int) called" << std::endl;
	_array = new T[n]();
	_size = n;
}

template <typename T>
Array<T>::Array(Array<T>& copy)
{
	std::cout << "Array copy costructor called" << std::endl;
	_size = copy.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = T(copy.getArray()[i]);
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T>& copy)
{
	std::cout << "Array copy assign operator called" << std::endl;
	delete[] _array;
	_size = copy.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = T(copy.getArray()[i]);
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) const
{
	if (index < _size)
		return _array[index];
	throw std::exception();
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

template <typename T>
T*				Array<T>::getArray(void) const
{
	return _array;
}
