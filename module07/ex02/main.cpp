#include "Array.hpp"
#include <string>

int main(void)
{
	try
	{
		Array	<std::string>arr1(3);
		arr1[0] = "string1";
		arr1[1] = "string2";
		Array	<std::string>arr2;
		arr2 = arr1;
		std::cout << "array1 size  = " << arr1.size() << std::endl;
		std::cout << "array2 size  = " << arr2.size() << std::endl;
		for (unsigned int i = 0; i < 3; i++)
		{
			std::cout << "arr1" << "'" << arr1[i] << "'" <<std::endl;
			std::cout << "arr2" << "'" << arr2[i] << "'" <<std::endl;
		}
		arr1[0] = "modified string";
		for (unsigned int i = 0; i < 3; i++)
		{
			std::cout << "arr1" << "'" << arr1[i] << "'" <<std::endl;
			std::cout << "arr2" << "'" << arr2[i] << "'" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}