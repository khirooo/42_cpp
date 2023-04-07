#include "RPN.hpp"


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: RPN <\"expression\">" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(argv[1]);
		rpn.solve();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
