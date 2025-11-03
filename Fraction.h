#pragma once
#include <iostream>

class Fraction
{
private:
    int num;
    int den;
public:
    Fraction();
    Fraction(int num, int den);
    int getNum() const;
    int getDen() const;
    void setNum(int num);
    void setDen(int den);
    Fraction operator+(const Fraction& obj) const;
    Fraction operator-(const Fraction& obj) const;
    Fraction operator*(const Fraction& obj) const;
    Fraction operator/(const Fraction& obj) const;
};
std::ostream& operator<<(std::ostream& out, const Fraction& f);

