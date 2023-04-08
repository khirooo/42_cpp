#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	(void)copy;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const & copy)
{
	(void)copy;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

static void insertionSort_vec(std::vector<int>& vec, int p, int q) 
{
	int i, key, j;
	for (i = p + 1; i <= q; i++)
	{
		key = vec[i];
		j = i - 1;
		while (j >= p && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		vec[j + 1] = key;
	}
}

static void insertionSort_q(std::deque<int>& que, int p, int q) 
{
	int i, key, j;
	for (i = p + 1; i <= q; i++)
	{
		key = que[i];
		j = i - 1;
		while (j >= p && que[j] > key)
		{
			que[j + 1] = que[j];
			j = j - 1;
		}
		que[j + 1] = key;
	}   
}

static void merge_vec(std::vector<int>& vec, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	std::vector<int> LA(vec.begin() + p, vec.begin() + q + 1);
	std::vector<int> RA(vec.begin() + q + 1, vec.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i < r - p + 1; i++) {
		if (RIDX == n2) {
			vec[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			vec[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			vec[i] = LA[LIDX];
			LIDX++;
		} else {
			vec[i] = RA[RIDX];
			RIDX++;
		}
	}
}

static void merge_q(std::deque<int>& que, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	std::deque<int> LA(que.begin() + p, que.begin() + q + 1);
	std::deque<int> RA(que.begin() + q + 1, que.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i < r - p + 1; i++) {
		if (RIDX == n2) {
			que[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			que[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			que[i] = LA[LIDX];
			LIDX++;
		} else {
			que[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void	PmergeMe::sort_vec(std::vector<int>& vec, int p, int r)
{
	if (r - p > 3000) {
		int q = (p + r) / 2;
		sort_vec(vec, p, q);
		sort_vec(vec, q + 1, r);
		merge_vec(vec, p, q, r);
	} else {
		insertionSort_vec(vec, p, r);
	}
}

void	PmergeMe::sort_q(std::deque<int>& que, int p, int r)
{
	if (r - p > 3000) {
		int q = (p + r) / 2;
		sort_q(que, p, q);
		sort_q(que, q + 1, r);
		merge_q(que, p, q, r);
	} else {
		insertionSort_q(que, p, r);
	}
}
