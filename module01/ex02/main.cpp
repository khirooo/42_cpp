#include <iostream>
#include <string>

int	main(void)
{
	std::string	str("HI THIS IS BRAIN");
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "string adress: " << &str << std::endl;
	std::cout << "stringPTR value: " << stringPTR << std::endl;
	std::cout << "stringREF value: " << &stringREF<< std::endl;

	std::cout << "string value: " << str << std::endl;
	std::cout << "stringPTR points to: " << *stringPTR << std::endl;
	std::cout << "stringREF points to: " << stringREF<< std::endl;
	return (0);
}