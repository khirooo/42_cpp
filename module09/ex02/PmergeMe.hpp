#ifndef PMERGE_HPP
#define PMERGE_HPP
#include <iostream>
#include <vector>
#include <deque>

class	PmergeMe
{
	private:
	PmergeMe();
	PmergeMe(PmergeMe const & copy);
	PmergeMe&	operator=(const PmergeMe& copy);
	~PmergeMe();

	public:
	static	void    sort_vec(std::vector<int>& vec, int p, int r);
	static	void    sort_q(std::deque<int>& A, int p, int r);

};	

template<typename T>
bool	sorted(T const & container)
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		if (it + 1 != container.end() && *it <= *(it + 1))
			continue;
		break;
	}
	if (it + 1 == container.end())
		return true;
	return false;
}

template<typename T>
void	print(T const & vec)
{
	typename T::const_iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif
