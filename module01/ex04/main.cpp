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
	if (s1.empty())
	{
		std::cout << "S1 cannot be empty! U wanna do me like that ?!" << std::endl;
		return 1;
	}
	s2 = argv[3];

	//just to make outfile name :)
	tmp = infilename;
	tmp = tmp.append(".replace");
	char* outfilename = new char[tmp.length() + 1]; // no need to check it it throws an exception on fail
	strcpy(outfilename, tmp.c_str());

	infile.open(infilename);
	if (!infile.is_open())
	{
		std::cout << "error: enable to open " << infilename << std::endl;
		free(outfilename);
		return (1);
	}

	outfile.open(outfilename);
	if (!outfile.is_open())
	{
		std::cout << "error: enable to create " << outfilename << std::endl;
		infile.close();
		return (1);
	}
	
	while (!infile.eof())
	{
		int	pos = 0;
		std::string	r_line;
		getline(infile, line);
		if (infile.fail())
		{
			std::cout << "error: somthing went wrong while reading from " << infilename << std::endl;
			free(outfilename);
			infile.close();
			outfile.close();
			return (1);
		}
		r_line = line;
		while (pos != -1)
		{
			pos = line.find(s1);
			if (pos == -1)
				break;
			r_line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			line  = r_line;
		}
		outfile << r_line << std::endl;
		if (outfile.fail())
		{
			std::cout << "error: somthing went wrong while writing to " << outfilename << std::endl;
			free(outfilename);
			infile.close();
			outfile.close();
			return (1);
		}
	}
	infile.close();
	outfile.close();
	free(outfilename);
	return (0);
}
