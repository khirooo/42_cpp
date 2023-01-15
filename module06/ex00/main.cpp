#include "Convertor.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <string>" << std::endl;
		return 1;
	}
	try
	{
		Convertor convertor(argv[1]);
		convertor.print_values();
//		convertor.getIntValue();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}