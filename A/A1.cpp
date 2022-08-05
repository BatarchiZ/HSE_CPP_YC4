//
// Created by Iskander Sergazin on 10.03.2022.
//


#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<size_t> v1;
    if (n <= 3)
    {
        for(int i =0; i<n;i++)
        {
            v1.push_back(1);
        }
    }
    else
    {
        for(int i =0; i<3;i++)
        {
            v1.push_back(1);
        }

        for (int i = 0; i < n - 3; i++)
        {
            int counter = 0;
            size_t sum = 0;
            for (std::vector<size_t>::reverse_iterator it = v1.rbegin(); counter < 3; it++)
            {
                sum += *it;
                counter++;
            }
            v1.push_back(sum);
        }
    }
    for (size_t i: v1)
    {
        std::cout << i << ' ';
    }
    return 0;
}
