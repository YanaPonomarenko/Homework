#include "MyArray.h"
#include <iostream>
using namespace std;
//Point
Point::Point() 
{
    x = 0;
    y = 0;
}
Point::Point(int x, int y) 
{
    this->x = x;
    this->y = y;
}
void Point::setX(int x) 
{ 
    this->x = x; 
}
void Point::setY(int y) 
{ 
    this->y = y; 
}
int Point::getX() const 
{ 
    return x; 
}
int Point::getY() const 
{ 
    return y; 
}

void Point::valueUp(int n) 
{
    x += n;
    y += n;
}

int Point::sum() const 
{
    return x + y;
}

void Point::print() const 
{
    cout << "(" << x << "  " << y << ")";
}

ostream& operator<<(ostream& os, const Point& p) 
{
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}
//MyArray
template <typename T>
MyArray<T>::MyArray() : size(0), arr(nullptr) {}

template <typename T>
MyArray<T>::MyArray(unsigned int size) : size(size) 
{
    arr = new T[size];
}

template <typename T>
MyArray<T>::~MyArray() 
{
    delete[] arr;
}

template <typename T>
void MyArray<T>::printElement() const 
{
    for (unsigned int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void MyArray<T>::valueUp(int n) 
{
    for (unsigned int i = 0; i < size; i++) 
    {
        arr[i].valueUp(n);
    }
}

template <typename T>
int MyArray<T>::sumElement() const {
    int total = 0;
    for (unsigned int i = 0; i < size; i++) 
    {
        total += arr[i].sum();
    }
    return total;
}

template <typename T>
unsigned int MyArray<T>::getSize() const {
    return size;
}

template <typename T>
void MyArray<T>::setElement(unsigned int index, const T& value) 
{
    if (index < size) 
    {
        arr[index] = value;
    }
}

template <typename T>
T MyArray<T>::getElement(unsigned int index) const 
{
    if (index < size) 
    {
        return arr[index];
    }
    return T();
}

template class MyArray<Point>;