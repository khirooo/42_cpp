#include <iostream>

#include "easyfind.hpp"

int main(void)
{
	std::list<int>		list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	std::vector<int>	vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	std::array<int, 3>	array = {1, 2, 3};

	std::list<int>::iterator	it_list = ::easyfind(list, 1);
	std::vector<int>::iterator	it_vector = ::easyfind(vector, 3);
	std::array<int, 3>::iterator	it_array = ::easyfind(array, 0);

	if (it_list != list.end())
		std::cout << "found " << *it_list << " in list" << std::endl;
	else
		std::cout << "number not found in list " << std::endl;

	std::cout << std::endl;

	if (it_vector != vector.end())
		std::cout << "found " << *it_vector << " in vector" << std::endl;
	else
		std::cout << "number not found in vector " << std::endl;

	std::cout << std::endl;

	if (it_array != array.end())
		std::cout << "found " << *it_array << " in array" << std::endl;
	else
		std::cout << "number not found in array " << std::endl;

	std::cout << std::endl;
	return (0);
}