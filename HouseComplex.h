#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Human 
{
private:
    char* fullName;
    int age;

public:
    Human();
    Human(const char* name, int a);
    Human(const Human& obj);
    ~Human();

    Human& operator=(const Human& obj);

    const char* getFullName() const;
    int getAge() const;

    void setFullName(const char* name);
    void setAge(int a);

    void showInfo() const;
};
class Apartment 
{
private:
    Human* residents;
    int residentCount;

public:
    Apartment();
    Apartment(const Apartment& obj);
    ~Apartment();

    Apartment& operator=(const Apartment& obj);

    void addResident(const Human& resident);
    void removeResident(int index);
    int getResidentCount() const;

    void showInfo() const;
};
class HouseComplex
{
private:
    char* address;
    int floors;
    int apartmentsCount;
    Apartment* apartments;

public:
    HouseComplex();
    HouseComplex(const char* addr, int f, int count);
    HouseComplex(const HouseComplex& obj);
    ~HouseComplex();

    HouseComplex& operator=(const HouseComplex& obj);

    void addApartment(const Apartment& apartment);
    void showInfo() const;
};

