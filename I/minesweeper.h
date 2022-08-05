//
// Created by Iskander Sergazin on 17.03.2022.
//

#ifndef YC4_MINESWEEPER_H
#define YC4_MINESWEEPER_H


#include <iostream>
#include <vector>

using std::vector;

class Minesweeper
{

public:

    //Constructor:
    Minesweeper(size_t m, size_t n)
            : _M(m), _N(n)
    {
        _Table.resize(m);
        for (vector<int> &i: _Table)
        {
            i.resize(n);
        }
    }


    //Get func's for R && C
    size_t Rows() const
    { return _M; }

    size_t Columns() const
    { return _N; }

    //Function Crash
    std::vector<vector<int>> &getTable()
    { return _Table; }

    void SetMine(size_t i, size_t j)
    {
        _Table[i][j] = -1;
    }

//    void SetMine(size_t i, size_t j) {
//        std::vector<vector<int>> t = getTable();
//        t[i][j] = -1;
//    }

    int operator()(size_t i, size_t j) const
    { return _Table[i][j]; }

    void CheckForMinesAround()
    {
        for (size_t i = 0; i != _M; ++i)
            for (size_t j = 0; j != _N; ++j)
                _CheckForMinesAround(i, j); //What is this?
    }

private:
    //Declare V's
    size_t _M, _N;
    vector<vector<int>> _Table;


    void _CheckForMinesAround(size_t i, size_t j)
    {
        int counter = 0;
        if (_Table[i][j] == -1)
        { return; }
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if ((0 <= i + dx && i + dx < _M && 0 <= j + dy && j + dy < _N) && (_Table[i + dx][j + dy] == -1))
                {++counter;}
            }
        }
        _Table[i][j] = counter;
    }
};

std::ostream &operator<<(std::ostream &out, const Minesweeper &ms);
std::ostream& operator << (std::ostream& out, const Minesweeper& ms)
{
    for (size_t i = 0; i != ms.Rows(); ++i)
    {
        for (size_t j = 0; j != ms.Columns(); ++j)
        {if (ms(i, j) == -1)
            {
                out << '*';
            }
            else
            {
                out << ms(i, j);
            }
        }
        out << "\n";
    }
    return out;
}

#endif //YC4_MINESWEEPER_H
