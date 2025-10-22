#include <iostream>
#include "Fraction.h"
using namespace std;

double Fraction::sum(Fraction& obj)
{
    return (double)this->numerator / this->denominator + (double)obj.numerator / obj.denominator;
}
double Fraction::subtraction(Fraction& obj) 
{
    return (double)this->numerator / this->denominator - (double)obj.numerator / obj.denominator;
}

double Fraction::multiply(Fraction& obj) 
{
    return ((double)this->numerator / this->denominator) * ((double)obj.numerator / obj.denominator);
}

double Fraction::division(Fraction& obj) 
{
    if (obj.numerator == 0) 
    {
        cout << "На нуль ділити не можна" << endl;
        return 0;
    }
    return ((double)this->numerator / this->denominator) / ((double)obj.numerator / obj.denominator);
}