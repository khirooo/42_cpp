#include "PmergeMe.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <iomanip>

static bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

static	std::vector<int>	check_input(int argc, char** argv)
{
	std::vector<int>	args;
	if (argc < 2)
	{
		std::cerr << "Usage: PmergeMe <num>*" << std::endl;
			throw std::exception();
	}
	int nb;
	for (int i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			std::cerr << "Error: Invalid input (not a number)" << std::endl;
			throw std::exception();
		}
		nb = atoi(argv[i]);
		if (std::find(args.begin(), args.end(), nb) != args.end())
		{
			std::cerr << "Error: Invalid input (duplicates)" << std::endl;
			throw std::exception();
		}
		args.push_back(nb);
	}
	return args;
}

int	main(int argc, char** argv)
{
	try
	{
		clock_t startTime, endTime, diff_vec, diff_que;

		std::vector<int>	args_vec = check_input(argc, argv);
		std::deque<int>		args_que(args_vec.begin(), args_vec.end());
		std::cout << "Before: ";
		print(args_vec);
	
		startTime = clock();
		PmergeMe::sort_q(args_que, 0, args_que.size() - 1);
		endTime = clock();

		diff_que = endTime - startTime;
		if (!sorted(args_que))
		{
			std::cerr << "Error: sorting failed for some reason ¯\\_(⊙︿⊙)_/¯" << std::endl;
			return 1;
		}

		startTime = clock();
		PmergeMe::sort_vec(args_vec, 0, args_vec.size() - 1);
		endTime = clock();
		
		diff_vec = endTime - startTime;
		if (!sorted(args_vec))
		{
			std::cerr << "Error: sorting failed for some reason ¯\\_(⊙︿⊙)_/¯" << std::endl;
			return 1;
		}

		std::cout << "After:  ";
		print(args_que);

		std::cout << "Time to process a range of "<< args_vec.size() << " elements with std::vector : " <<std::fixed << std::setprecision(7) << (double)diff_vec / CLOCKS_PER_SEC << "s" << std::endl;
		std::cout << "Time to process a range of "<< args_que.size() << " elements with std::dque : " << (double)diff_que / CLOCKS_PER_SEC << "s" << std::endl;
	}
	catch(std::exception& e)
	{
		return 1;
	}
	return 0;
}