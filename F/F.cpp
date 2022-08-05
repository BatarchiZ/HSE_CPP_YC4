#include <iostream>
#include <set>
#include <vector>
int main()
{
    int n;
    int k;
    std::cin >> n >> k;
//    std::multiset<int> ms = {0,1,1};
    std::multiset<int> ms;
    std::vector<int> v;
    for(int j = 0; j< k ; j++)
    {
        int num;
        std::cin >> num;
        ms.insert(num);
        v.push_back(num);
    }
    std::cout << *(ms.begin()) << std::endl;
//    ms.erase(ms.begin()); // Erase by value
//    ms.erase(v[0]);
    ms.erase(ms.lower_bound(v[0]));
//    std::multiset<int>::const_iterator it = ms.find(v[0]);
//    if(it!= ms.end())
//    {
////        it = ms.erase(it);
//        ms.erase(it);
//    }
    for(int i = 0; i < n-k; i++)
    {
        int num;
        std::cin >> num;
        ms.insert(num);
        v.push_back(num);
        std::cout << *(ms.begin()) << std::endl;
//        ms.erase(v[i+1]) erases all occurrences
        ms.erase(ms.lower_bound(v[i+1])); //Compilation error fsr
//    std::multiset<int>::const_iterator it = ms.find(v[i+1]);
//    if(it!= ms.end())
//    {
////        it = ms.erase(it);
//        ms.erase(it);
//    }
    }
    return 0;
}
//7 1
//1 1 1 1 2 2 2
