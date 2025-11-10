#pragma once
#include <iostream>
using namespace std;

class Point 
{
private:
    int x;
    int y;

public:
    Point();
    Point(int x, int y);

    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;

    void valueUp(int n);
    int sum() const;
    void print() const;
};
ostream& operator<<(ostream& os, const Point& p);

template <typename T>
class MyArray 
{
private:
    unsigned int size;
    T* arr;
public:
    MyArray();
    MyArray(unsigned int size);
    ~MyArray();

    void printElement() const;
    void valueUp(int n);
    int sumElement() const;

    unsigned int getSize() const;
    void setElement(unsigned int index, const T& value);
    T getElement(unsigned int index) const;
};