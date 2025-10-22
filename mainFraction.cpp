#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	Fraction fr1(9, 4);
	Fraction fr2(5, 8);

    cout << "Сума " << fr1.sum(fr2) << endl;
    cout << "Різниця " << fr1.subtraction(fr2) << endl;
    cout << "Добуток " << fr1.multiply(fr2) << endl;
    cout << "Частка " << fr1.division(fr2) << endl;

    return 0;

}