#include <iostream>
#include "MyArray.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
 
    cout << "\nКонструктор з розміром" <<endl;
    MyArray arr1(5);
    arr1.printArray();

    cout << "\n--Заповнення масива" <<endl;
    arr1.fillArray();
    arr1.printArray();

    cout << "\n--Конструктор копіювання" <<endl;
    MyArray arr2 = arr1;
    cout << "Копія масива" <<endl;
    arr2.printArray();

    cout << "\n--Мінімальне та максимальне значення" <<endl;
    cout << "Мінімальне: " << arr1.getMin() <<endl;
    cout << "Максимальне: " << arr1.getMax() <<endl;

    cout << "\n--Сортування масиву" <<endl;
    arr1.sortArray();
    cout << "Відсортований масив:"  <<endl;
    arr1.printArray();
    
    cout << "\nСума елементів: " << arr1.getSum() <<endl;

   
    cout << "\n--Пошук елемента:" <<endl;
    int element;
    cout << "Введіть для пошуку елемента ";
    cin >> element;
    int index = arr1.findIndex(element);
    if (index != -1) 
    {
        cout << "Елемент " << element << " знайдено на позиції " << index <<endl;
    }
    else 
    {
        cout << "Елемент " << element << " не знайдено" <<endl;
    }

    cout << "\n--Зміна розміру масиву" <<endl;
    cout << "До зміни розміру:" <<endl;
    arr1.printArray();

    arr1.setSize(10);
    cout << "Після збільшення до 10:" <<endl;
    arr1.printArray();

    arr1.setSize(2);
    cout << "Після зменшення до 2:" <<endl;
    arr1.printArray();


    return 0;
}