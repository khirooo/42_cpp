#include "PmergeMe.hpp"
#include <sys/time.h>

// static void	print_arr(std::vector<int> const & vec)
// {
// 	std::vector<int>::const_iterator it;
// 	for (it = vec.begin(); it != vec.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

// static void	print_q(std::deque<int>& vec)
// {
// 	std::deque<int>::const_iterator it;
// 	for (it = vec.begin(); it != vec.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

PmergeMe::PmergeMe(const std::vector<int>& seq)
:
sequence_(seq)
{
}


static void insertionSort_vec(std::vector<int>& arr, int p, int q) 
{
	int i, key, j;
    for (i = p + 1; i <= q; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= p && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

static void insertionSort_q(std::deque<int>& arr, int p, int q) 
{
	int i, key, j;
    for (i = p + 1; i <= q; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= p && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

static void merge_vec(std::vector<int>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

	std::vector<int> LA(A.begin() + p, A.begin() + q + 1);
	std::vector<int> RA(A.begin() + q + 1, A.begin() + r + 1);
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i < r - p + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

static void merge_q(std::deque<int>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

	std::deque<int> LA(A.begin() + p, A.begin() + q + 1);
	std::deque<int> RA(A.begin() + q + 1, A.begin() + r + 1);
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i < r - p + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

void    PmergeMe::sort_vec(std::vector<int>& A, int p, int r)
{
    if (r - p > 10) {
        int q = (p + r) / 2;
        sort_vec(A, p, q);
        sort_vec(A, q + 1, r);
        merge_vec(A, p, q, r);
    } else {
        insertionSort_vec(A, p, r);
    }
}

void    PmergeMe::sort_q(std::deque<int>& A, int p, int r)
{
    if (r - p > 10) {
        int q = (p + r) / 2;
        sort_q(A, p, q);
        sort_q(A, q + 1, r);
        merge_q(A, p, q, r);
    } else {
        insertionSort_q(A, p, r);
    }
}

// void	PmergeMe::sort()
// {
//     timeval startTime, endTime;
// 	std::cout << "Before sort: ";
// 	print_arr(sequence_);
//     std::deque<int> que(sequence_.begin(), sequence_.end());
//     gettimeofday(&startTime, NULL);
//     sort_vec(sequence_, 0, sequence_.size() - 1);
//     gettimeofday(&endTime, NULL);
//     long elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1000000;
//     elapsedTime += endTime.tv_usec - startTime.tv_usec;
//     std::cout << "After sort:  ";
//     //print_arr(sequence_);
//     std::cout << "sorting time: " << elapsedTime << "sec" << std::endl;
//     std::cout << "Before sort: ";
//      gettimeofday(&startTime, NULL);
//     sort_q(que, 0, que.size() - 1);
//      gettimeofday(&endTime, NULL);
// 	std::cout << "After sort:  ";
//     elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1000000;
//     elapsedTime += endTime.tv_usec - startTime.tv_usec;
//     std::cout << "sorting time: " << elapsedTime << "microseconds" << std::endl;
// }

PmergeMe::~PmergeMe()
{
}

const char* PmergeMe::InvalidInput::what() const throw()
{
	return "Error: Invalide input";
}
