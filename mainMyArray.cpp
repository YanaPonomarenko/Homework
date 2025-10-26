#include <iostream>
#include "MyArray.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int arr[] = { 5, 2, 8, 1, 9 };
    int size = 5;

    MyArray myArr(arr, size);

    myArr.printArray();

 
    cout << "Сума " << myArr.getSum() <<endl;

    myArr.sortArray();
    cout << "Після сортування ";
    myArr.printArray();

    int index = myArr.findIndex(8);
    if (index != -1) 
    {
        cout << "Елемент 8 на позиції: " << index <<endl;
    }
    else 
    {
        cout << "Елемент 8 не знайден" <<endl;
    }

    cout << "\nПеревірка зміни розміра:" <<endl;
    myArr.setSize(7);
    myArr.printArray();

    return 0;
}