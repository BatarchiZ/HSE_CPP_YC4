#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::string str;

    while (n > k)
    {
        str += '0';
        n -= 1;
    }

    while(k != 0)
    {
        str+= '1';
        k -= 1;
    }
    do
    {
        std::cout << str << std::endl;
    }
    while(std::next_permutation(str.begin(), str.end()));
    return 0;
}
