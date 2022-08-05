#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

typedef std::pair<long long int, long long int> MyPair;
typedef std::vector<std::string> StrV;
typedef std::vector<int> IntV;

MyPair getParams(std::ifstream &fi)
{
    std::string str;
    getline(fi, str, ' ');
    MyPair p2{(stoi(str)), 0};
    getline(fi, str);
    p2.second = stoi(str);
    return p2;
}

IntV getCompV(std::ifstream &fi, MyPair &p)
{
    IntV v1;
    std::string dummy;
    getline(fi, dummy, ' ');
//    long long int prod = 1;
    for (int i = 0; i < p.second - 1; i++)
    {
        getline(fi, dummy, ' ');
        v1.push_back(stoi(dummy));
    }
    getline(fi, dummy);
    v1.push_back(stoi(dummy));
    return v1;
}


int getScSum(IntV &vComp, IntV &v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += vComp[i] * v[i];
    }
    return sum;
}

void readLine(std::stringstream &fi, StrV &v1, MyPair &p, long long int &max, IntV &vComp)
{
    IntV v2;
    std::string name;
    std::string dummy;
    getline(fi, name, ' ');

    for (int i = 0; i < p.second; i++)
    {
        getline(fi, dummy, ' ');
        v2.push_back(stoi(dummy));
    }


    int sum = getScSum(vComp, v2);
    if (max == sum)
    {
        v1.push_back(name);
    }
    if (max < sum)
    {
        max = sum;
        v1 = {};
        v1.push_back(name);
    }
}

void readRest(std::ifstream &fi, StrV &v1, MyPair &p, IntV &compV)
{
    long long int max = -99999999999999999;
    for (int i = 0; i < p.first - 1; i++)
    {
        std::string str;
        getline(fi, str);
        std::stringstream ss(str);
        readLine(ss, v1, p, max, compV);
    }
}

int main()
{
    //Read File
//    std::string INP_FILE = "/Users/iskandersergazin/Desktop/HSE_CPP/YC4/E/input.txt";
    std::string INP_FILE = "input.txt";
    std::ifstream input_file;
    input_file.open(INP_FILE);
    //Get Parameters
    MyPair p = getParams(input_file);

    //First Line && Get CompVector
    IntV compV = getCompV(input_file, p);
    //Read Rest
    StrV v1;
    readRest(input_file, v1, p, compV);
    //output vector
    for (const auto &i: v1)
    {
        std::cout << i << std::endl;
    }
    return 0;
}

