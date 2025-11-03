#include "HouseComplex.h"

Human::Human() : fullName(nullptr), age(0) {}

Human::Human(const char* name, int a) 
{
    size_t len = strlen(name) + 1;
    fullName = new char[len];
    strcpy_s(fullName, len, name);
    age = a;
}

Human::Human(const Human& obj) 
{
    size_t len = strlen(obj.fullName) + 1;
    fullName = new char[len];
    strcpy_s(fullName, len, obj.fullName);
    age = obj.age;
}

Human::~Human() 
{
    delete[] fullName;
}

Human& Human::operator=(const Human& obj) 
{
    if (this != &obj) {
        delete[] fullName;
        size_t len = strlen(obj.fullName) + 1;
        fullName = new char[len];
        strcpy_s(fullName, len, obj.fullName);
        age = obj.age;
    }
    return *this;
}

const char* Human::getFullName() const 
{
    return fullName;
}

int Human::getAge() const 
{
    return age;
}

void Human::setFullName(const char* name) 
{
    delete[] fullName;
    size_t len = strlen(name) + 1;
    fullName = new char[len];
    strcpy_s(fullName, len, name);
}

void Human::setAge(int a) 
{
    age = a;
}

void Human::showInfo() const 
{
    cout << "    " << fullName << ", Age: " << age << endl;
}

Apartment::Apartment() : residents(nullptr), residentCount(0) {}

Apartment::Apartment(const Apartment& obj) 
{
    residentCount = obj.residentCount;
    residents = new Human[residentCount];
    for (int i = 0; i < residentCount; ++i)
        residents[i] = obj.residents[i];
}

Apartment::~Apartment() 
{
    delete[] residents;
}

Apartment& Apartment::operator=(const Apartment& obj) 
{
    if (this != &obj) {
        delete[] residents;
        residentCount = obj.residentCount;
        residents = new Human[residentCount];
        for (int i = 0; i < residentCount; ++i)
            residents[i] = obj.residents[i];
    }
    return *this;
}

void Apartment::addResident(const Human& resident) 
{
    Human* newResidents = new Human[residentCount + 1];

    for (int i = 0; i < residentCount; ++i)
        newResidents[i] = residents[i];

    newResidents[residentCount] = resident;

    delete[] residents;
    residents = newResidents;
    residentCount++;
}

void Apartment::removeResident(int index) 
{
    if (index < 0 || index >= residentCount) return;

    Human* newResidents = new Human[residentCount - 1];

    for (int i = 0, j = 0; i < residentCount; ++i) 
    {
        if (i != index) {
            newResidents[j++] = residents[i];
        }
    }

    delete[] residents;
    residents = newResidents;
    residentCount--;
}

int Apartment::getResidentCount() const 
{
    return residentCount;
}

void Apartment::showInfo() const 
{
    cout << "Apartment with " << residentCount << " residents:" << endl;
    for (int i = 0; i < residentCount; ++i) 
    {
        residents[i].showInfo();
    }
}

HouseComplex::HouseComplex() : address(nullptr), floors(0), apartmentsCount(0), apartments(nullptr) {}

HouseComplex::HouseComplex(const char* addr, int f, int count) 
{
    size_t len = strlen(addr) + 1;
    address = new char[len];
    strcpy_s(address, len, addr);

    floors = f;
    apartmentsCount = 0;
    apartments = new Apartment[count];
}

HouseComplex::HouseComplex(const HouseComplex& obj) 
{
    size_t len = strlen(obj.address) + 1;
    address = new char[len];
    strcpy_s(address, len, obj.address);

    floors = obj.floors;
    apartmentsCount = obj.apartmentsCount;

    apartments = new Apartment[apartmentsCount];
    for (int i = 0; i < apartmentsCount; ++i)
        apartments[i] = obj.apartments[i];
}

HouseComplex::~HouseComplex() 
{
    delete[] address;
    delete[] apartments;
}

HouseComplex& HouseComplex::operator=(const HouseComplex& obj) 
{
    if (this != &obj) 
    {
        delete[] address;
        delete[] apartments;

        size_t len = strlen(obj.address) + 1;
        address = new char[len];
        strcpy_s(address, len, obj.address);

        floors = obj.floors;
        apartmentsCount = obj.apartmentsCount;

        apartments = new Apartment[apartmentsCount];
        for (int i = 0; i < apartmentsCount; ++i)
            apartments[i] = obj.apartments[i];
    }
    return *this;
}

void HouseComplex::addApartment(const Apartment& apartment) 
{
    Apartment* newApartments = new Apartment[apartmentsCount + 1];

    for (int i = 0; i < apartmentsCount; ++i)
        newApartments[i] = apartments[i];

    newApartments[apartmentsCount] = apartment;

    delete[] apartments;
    apartments = newApartments;
    apartmentsCount++;
}

void HouseComplex::showInfo() const {
    cout << "House Complex " << address << endl;
    cout << "Floors " << floors << ", Apartments " << apartmentsCount << endl;
    for (int i = 0; i < apartmentsCount; ++i) {
        apartments[i].showInfo();
        if (i < apartmentsCount - 1) cout << endl;
    }
}