#include "MyString.h"
#include <cstring>
#include <iostream>

using namespace std;

int MyString::counter = 0;

MyString::MyString() 
{
    this->size = 0;
    this->str = nullptr;
    counter++;
}

MyString::MyString(const char* input) 
{
    this->size = 0;
    this->str = nullptr;

    if (input != nullptr) 
    {
        this->size = strlen(input);
        this->str = new char[this->size + 1];
        strcpy_s(this->str, this->size + 1, input);
    }
    counter++;
}

MyString::MyString(size_t newSize) 
{
    this->size = newSize;

    if (newSize > 0) 
    {
        this->str = new char[newSize + 1];
        for (size_t i = 0; i < newSize; i++) 
        {
            this->str[i] = '_';
        }
        this->str[newSize] = '\0';
    }
    else {
        this->str = nullptr;
    }
    counter++;
}

MyString::~MyString() 
{
    delete[] this->str;
    counter--;
}

size_t MyString::getSize() const 
{
    return this->size;
}

void MyString::setSize(size_t newSize) 
{
    if (newSize == this->size) return;
    char* newStr = new char[newSize + 1];
    for (size_t i = 0; i < newSize; i++) 
    {
        newStr[i] = '_';
    }
    newStr[newSize] = '\0';

    delete[] this->str;
    this->str = newStr;
    this->size = newSize;
}

const char* MyString::getStr() const 
{
    if (str == nullptr) 
    {
        return "[empty]";
    }
    return str;
}

void MyString::setStr(const char* newStr) 
{
    if (this->str != nullptr)
    {
        delete[] this->str;
    }

    if (newStr == nullptr) 
    {
        this->size = 0;
        this->str = nullptr;
    }
    else 
    {
        this->size = strlen(newStr);
        this->str = new char[this->size + 1];
        strcpy_s(this->str, this->size + 1, newStr);
    }
}
int MyString::getCounter() 
{
    return counter;
}
void MyString::myStrcpy(MyString& obj) 
{
    if (this->str != nullptr) 
    {
        delete[] this->str;
    }

    if (obj.str == nullptr) 
    {
        this->size = 0;
        this->str = nullptr;
    }
    else {
        this->size = obj.size;
        this->str = new char[this->size + 1];
        strcpy_s(this->str, this->size + 1, obj.str);
    }
}
void MyString::myDeleteChar(char c) 
{
    if (this->str == nullptr) return;

    int index = -1;
    for (size_t i = 0; i < this->size; i++) 
    {
        if (this->str[i] == c) 
        {
            index = i;
            break;
        }
    }
    if (index == -1) return; 

    char* newStr = new char[this->size];
    size_t newIndex = 0;

    for (size_t i = 0; i < this->size; i++) 
    {
        if (i != index) 
        {
            newStr[newIndex] = this->str[i];
            newIndex++;
        }
    }
    newStr[newIndex] = '\0';

    delete[] this->str;
    this->str = newStr;
    this->size = newIndex;
}
int MyString::myCharIndex(char c) 
{
    if (!str) return -1;

    for (size_t i = 0; i < size; i++) 
    {
        if (str[i] == c) 
        {
            return static_cast<int>(i);  
        }
    }
    return -1;
}