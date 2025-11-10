/*#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	Student student1;

	int grades2[5] = { 95,90,87,96,91 };
	Student student2("Тарас", 20, grades2);

	int grades3[5] = { 90,95,99,94,92 };
	Student student3("Марія", 19, grades3);

    Student student4;
    student4.setName("Олександр");
    student4.setAge(21);
    student4.setGrade(0, 85);
    student4.setGrade(1, 78);
    student4.setGrade(2, 92);
    student4.setGrade(3, 88);
    student4.setGrade(4, 90);

    char name[100];

    student1.getName(name);
    cout << "Студент 1: " << name << ", " << student1.getAge() << " років\nCередній бал: " << student1.getAverage() <<endl;

    student2.getName(name);
    cout << "Студент 2: " << name << ", " << student2.getAge() << " років\nCередній бал: " << student2.getAverage() <<endl;

    student3.getName(name);
    cout << "Студент 3: " << name << ", " << student3.getAge() << " років" << endl;
    cout << "Всі оцінки більше 90: ";
    if (student3.isExcellent()) 
    {
        cout << "так" << endl;
    }
    else {
        cout << "ні" << endl;
    }

    student4.getName(name);
    cout << "Студент 4: " << name << ", " << student4.getAge() << " років\nCередній бал: " << student4.getAverage() <<endl;
   
    return 0;
}*/
