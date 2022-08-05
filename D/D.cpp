#include <iostream>
#include <algorithm>

int main()
{
    int number;
    std::cin >> number;
    std::string sNumber = "";
    int i = number-1;
    while (number != 0)
    {
//        int nNumber = number;
        sNumber += std::to_string(number);
        number -= 1;
        i--;
    }
    std::sort(sNumber.begin(), sNumber.end());
    do
    {
        std::cout << sNumber << std::endl;
    }
    while(std::next_permutation(sNumber.begin(), sNumber.end()));
    return 0;
}
