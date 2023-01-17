#include "Iter.hpp"

#include <string>

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, &print);
    std::cout << std::endl;

    float array2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(array2, 5, &print);
    std::cout << std::endl;

    std::string array3[5] = {"1", "2", "3", "4", "5"};
    iter(array3, 5, &print);
    std::cout << std::endl;
	
    return 0;
}