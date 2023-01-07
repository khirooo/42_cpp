#include<iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] <= 'z'&&  argv[i][j] >= 'a')
					std::cout << (char)(argv[i][j] - 32);
				else
					std::cout << argv[i][j];
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
