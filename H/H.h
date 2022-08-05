//
// Created by Iskander Sergazin on 19.03.2022.
//

#ifndef YC4_HFINAL_H
#define YC4_HFINAL_H

#include <iostream>
#include <cstdlib>

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

class Rational
{

public:
    Rational(int num = 0, int denom = 1)
            : _num(num), _denom(denom)
    {
        _reduce();
    }

    int numerator() const
    { return _num; }

    int denominator() const
    { return _denom; }

    ///Addition
    Rational operator+(const Rational &rhs) const
    {
        return {(_denom * rhs._num) + (rhs._denom * _num), (_denom * rhs._denom)};
    }

    Rational operator+(int rhs) const
    {
        return {(_num + (rhs * _denom)), (_denom)};
    }

    ///Subtract
    Rational operator-(const Rational &rhs) const
    {
        return {(rhs._denom * _num) - (_denom * rhs._num), _denom * rhs._denom};
    }

    Rational operator-(int rhs) const
    {
        return {(_num - rhs * _denom), (_denom)};
    }

    ///Multiply
    Rational operator*(const Rational &rhs) const
    {
        return {rhs._num * _num, rhs._denom * _denom};
    }

    Rational operator*(int rhs) const
    {
        return {rhs * _num, _denom};
    }

    //Division
    Rational operator/(const Rational &rhs) const
    {
        return {_num * rhs._denom, _denom * rhs._num};
    }

    Rational operator/(int rhs) const
    {
        return {_num, _denom * rhs};
    }

    Rational operator+() const
    {
        return {_num, _denom};
    }

    Rational operator-() const
    {
        return {(-1) * (_num), _denom};
    }

//Even faster is to just use this;
    Rational &operator+=(const Rational &rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    Rational &operator-=(const Rational &rhs)
    {
        *this = *this - rhs;
        return *this;
    }

    Rational &operator*=(const Rational &rhs)
    {
        *this = *this * rhs;
        return *this;
    }

    Rational &operator/=(const Rational &rhs)
    {
        *this = *this / rhs;
        return *this;
    }

    bool operator==(const Rational &rhs) const
    {
        if (rhs._denom * _num == _denom * rhs._num)
        { return true; }
        else
        { return false; }
    }

    bool operator!=(const Rational &rhs) const
    {
        if (!(*this == rhs))
        { return true; }
        else
        { return false; }
    }

    Rational &operator++()
    {
        *this = *this + 1;
        return *this;
    }

    Rational &operator--()
    {
        *this = *this - 1;
        return *this;
    }

    Rational operator++(int)
    {
        Rational r(*this);
        operator++();
        return r;
    }

    Rational operator--(int)
    {
        Rational r(*this);
        operator--();
        return r;
    }

    friend Rational operator+(int lhs, const Rational &r)
    {
        Rational rInt(lhs, 1);
        return {r + rInt};
    }

    friend Rational operator-(int lhs, const Rational &r)
    {
        Rational rInt(lhs, 1);
        return {rInt - r};
    }

    friend Rational operator*(int lhs, const Rational &r)
    {
        Rational r2Int(lhs, 1);
        return {r2Int * r};
    }

    friend Rational operator/(int lhs, const Rational &r)
    {
        Rational lInt(lhs, 1);
        return {lInt / r};
    }

private:
    int _num;
    int _denom;

    void _reduce()
    {
        int gcdInt = gcd(_num, _denom);
        _num = _num / gcdInt;
        if (_denom < 0)
        {
            _num = (-1) * _num;
        }
        _denom = abs(_denom / gcdInt);
    }
};

#endif //YC4_HFINAL_H

