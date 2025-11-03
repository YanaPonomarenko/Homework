#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() 
{
    num = 0;
    den = 1;
}

Fraction::Fraction(int num, int den) 
{
    this->num = num;
    this->den = den;
}

int Fraction::getNum() const 
{
    return this->num;
}

int Fraction::getDen() const 
{
    return this->den;
}

void Fraction::setNum(int num) 
{
    this->num = num;
}

void Fraction::setDen(int den) 
{
    this->den = den;
}

Fraction Fraction::operator+(const Fraction& obj) const 
{
    int new_num = this->num * obj.den + obj.num * this->den;
    int new_den = this->den * obj.den;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(const Fraction& obj) const 
{
    int new_num = this->num * obj.den - obj.num * this->den;
    int new_den = this->den * obj.den;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(const Fraction& obj) const 
{
    int new_num = this->num * obj.num;
    int new_den = this->den * obj.den;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator/(const Fraction& obj) const 
{
    int new_num = this->num * obj.den;
    int new_den = this->den * obj.num;
    return Fraction(new_num, new_den);
}

ostream& operator<<(ostream& out, const Fraction& f) 
{
    out << f.getNum() << "/" << f.getDen();
    return out;
}