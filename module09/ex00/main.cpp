#include "BitcoinExchange.hpp"


int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: btc <inputfile.txt>" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	if (input.empty() || input.size() < 5 || !(input.substr(input.size() - 4) == ".txt"))
	{
		std::cerr << "Wrong input file format (*.txt)" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bc;
	//	bc.print_db();
		bc.exchange(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
