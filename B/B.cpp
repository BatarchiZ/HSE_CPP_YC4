#include <iostream>

int main()
{
    long int a;
    long int b;
    std::cin >> a >> b;
    int res =1;
    long long int p = 1000000007;
    while(b > 0)
    {
//        a = a % p;
        if(b%2 !=0)
        {
            res = (res*a) % p;
//            a = (a*a)%p;
            b = b-1;
        }
        b = b / 2; //The same as bitwise shift
        a = (a*a) % p;
//        a = (a*a)%p;
    }
    std::cout << res;
    return 0;
}
