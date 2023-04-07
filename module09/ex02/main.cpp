#include "PmergeMe.hpp"
#include <sys/time.h>

static bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

static void	print_arr(std::vector<int> const & vec)
{
	std::vector<int>::const_iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// static void	print_q(std::deque<int>& vec)
// {
// 	std::deque<int>::const_iterator it;
// 	for (it = vec.begin(); it != vec.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

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
		// if (std::find(args.begin(), args.end(), nb) != args.end())
		// {
		// 	std::cerr << "Error: Invalid input (duplicates)" << std::endl;
		// 	throw std::exception();
		// }
		args.push_back(nb);
	}
	return args;
}

int	main(int argc, char** argv)
{
	try
	{
		timeval startTime, endTime;
		std::vector<int>	args_vec = check_input(argc, argv);
		std::deque<int>	args_que(args_vec.begin(), args_vec.end());
		print_arr(args_vec);
		PmergeMe pmerge(args_vec);
		gettimeofday(&startTime, NULL);
		pmerge.sort_vec(args_vec, 0, args_vec.size() - 1);
    	gettimeofday(&endTime, NULL);
		long elapsedTime_vec = (endTime.tv_sec - startTime.tv_sec) * 1000000;
    	elapsedTime_vec += endTime.tv_usec - startTime.tv_usec;


		gettimeofday(&startTime, NULL);
    	pmerge.sort_q(args_que, 0, args_que.size() - 1);
	    gettimeofday(&endTime, NULL);
		long lapsedTime_que = (endTime.tv_sec - startTime.tv_sec) * 1000000;
    	lapsedTime_que += endTime.tv_usec - startTime.tv_usec;
		print_arr(args_vec);
	}
	catch(std::exception& e)
	{
		return 1;
	}
	return 0;
}