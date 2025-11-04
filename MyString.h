#pragma once
class MyString
{
private:
    size_t size;
    char* str;
    static int counter;
public:
    MyString();
    MyString(const char* input);
    MyString(size_t newSize);

    ~MyString();

    size_t getSize() const;
    void setSize(size_t newSize);
    const char* getStr() const;
    void setStr(const char* newStr);

    static int getCounter();

    void myStrcpy(MyString& obj);
    void myDeleteChar(char c);
    int myCharIndex(char c);
};

