#include "HouseComplex.h"

int main() 
{
    Human h1("Ivan Petrenko", 35);
    Human h2("Maria Ivanenko", 32);
    Human h3("Oleksiy Kovalenko", 28);

    Apartment apt1;
    apt1.addResident(h1);
    apt1.addResident(h2);

    Apartment apt2;
    apt2.addResident(h3);

    HouseComplex complex("Shevchenko St. 10, Odesa", 5, 0);
    complex.addApartment(apt1);
    complex.addApartment(apt2);

    cout << "  Original" << endl;
    complex.showInfo();

    cout << "\n  Copied  " << endl;
    HouseComplex complexCopy = complex;
    complexCopy.showInfo();

    return 0;
}