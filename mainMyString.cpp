#include "MyString.h"
#include <iostream>
using namespace std;

int main() {
    cout << "test" << endl;

    MyString str1;
    MyString str2("Hello");
    MyString str3(4);

    cout << "Count: " << MyString::getCounter() << endl;
    cout << "str1: " << str1.getStr() << " (size: " << str1.getSize() << ")" << endl;
    cout << "str2: " << str2.getStr() << " (size: " << str2.getSize() << ")" << endl;
    cout << "str3: " << str3.getStr() << " (size: " << str3.getSize() << ")" << endl;

    cout << "Index of 'e': " << str2.myCharIndex('e') << endl;

    MyString str4("orange");
    cout << "before delete: " << str4.getStr() << endl;
    str4.myDeleteChar('n');
    cout << "after delete: " << str4.getStr() << endl;

    MyString str5;
    str5.myStrcpy(str2);
    cout << "copied: " << str5.getStr() << endl;

    return 0;
}