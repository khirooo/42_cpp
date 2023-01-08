#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

int	main(int argc, char *argv[])
{
	std::string	s1, s2, line, tmp;
	char* infilename;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4)
	{
		std::cout << argc ;
		std::cout << "error: invalid input" << std::endl;
		std::cout << "usage: ./replace <filename1> <string to replace> <string to replace with>" << std::endl;
		return (1);
	}
	infilename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	tmp = infilename;
	tmp = tmp.append(".replace");
	char* outfilename = new char[tmp.length() + 1];
	strcpy(outfilename, tmp.c_str());
	infile.open(infilename);
	if (!infile.is_open())
	{
		std::cout << "error: enable to open " << infilename << std::endl;
		return (1);
	}
	outfile.open(outfilename);
	if (!outfile.is_open())
	{
		std::cout << "error: enable to create " << outfilename << std::endl;
		return (1);
	}
	
	while (!infile.eof())
	{
		int	pos = 0;
		std::string	rline;
		getline(infile, line);
		if (infile.fail())
		{
			std::cout << "error: somthing went wrong while reading from " << infilename << std::endl;
			return (1);
		}
		rline = line;
		while (pos != -1)
		{
			pos = line.find(s1);
			if (pos == -1)
				break;
			rline = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			line  = rline;
		}
		outfile << rline << std::endl;
		if (outfile.fail())
		{
			std::cout << "error: somthing went wrong while writing to " << outfilename << std::endl;
			return (1);
		}
	}
	infile.close();
	outfile.close();
	return (0);
}
