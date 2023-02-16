#include "ScalarConverter.hpp"

std::string ScalarConverter::_representation;
type		ScalarConverter::_type;
std::string	ScalarConverter::_values[4];
int			ScalarConverter::_int_value;
char		ScalarConverter::_char_value;
float		ScalarConverter::_float_value;
double		ScalarConverter::_double_value;

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <string>" << std::endl;
		return 1;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
		//system("leaks convert");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}