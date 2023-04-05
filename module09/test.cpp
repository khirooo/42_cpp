#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#include <sstream>

int main(void)
{
	std::string	s = "44334.33";
	std::istringstream ss(s); 
	// std::string s1,s2;
	// char d;
	long double v;
	double v2;
	double v3 = 44334.33;
	std::cin >> v2;
	ss >> v;
	if (ss.fail())
		std::cout << "something went wrong " <<std::endl;
	std::cout << v<< " | " << v2<< " | "<< v3 <<std::endl;
	return 0;
}