#ifndef PMERGE_HPP
#define PMERGE_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>

class	PmergeMe
{
	private:
	std::vector<int>			sequence_;
	std::vector<int>	vec_;
	std::deque<int>		que_;
	
	public:
	PmergeMe(const std::vector<int>& seq);
	~PmergeMe();
	//void	sort(void);

	void    sort_vec(std::vector<int>& A, int p, int r);
	void    sort_q(std::deque<int>& A, int p, int r);

	class	InvalidInput: public std::exception
	{
		const char* what() const throw();
	};
};	

#endif


// static void merge(std::vector<int>& arr, int l, int m, int r)
// {
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;
 
//     std::vector<int> L(n1), R(n2);
 
//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];
 
//     i = 0; 
//     j = 0; 
//     k = l; 

//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
 
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
 
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
 
// // Merge-Insertion sort function
// static void mergeInsertionSort(std::vector<int>& arr, int l, int r, int k)
// {
//     if (l < r) {
//         if (r - l <= k) {
//             for (int i = l + 1; i <= r; ++i) {
//                 int key = arr[i];
//                 int j = i - 1;
//                 while (j >= l && arr[j] > key) {
//                     arr[j + 1] = arr[j];
//                     j--;
//                 }
//                 arr[j + 1] = key;
//             }
//         }
//         else {
//             int m = l + (r - l) / 2;
//             mergeInsertionSort(arr, l, m, k);
//             mergeInsertionSort(arr, m + 1, r, k);
//             merge(arr, l, m, r);
//         }
//     }
// }