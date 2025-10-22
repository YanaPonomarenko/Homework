#pragma once
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) 
    {
        numerator = num;
        denominator = den;
    }
    
    double sum(Fraction& obj);
    double subtraction(Fraction& obj);
    double multiply(Fraction& obj);
    double division(Fraction& obj);
};

