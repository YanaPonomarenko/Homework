/*#include <iostream>

Student::Student()
{
	name = new char[50];
	strcpy_s(name,50, "NoName");
	age = 0;
	for (int i = 0; i < 5; i++)
	{
		grades[i] = 0;
	}
}
//власні дані
Student::Student(const char* studentName, int studentAge,int studentGrades[5])
{
	name = new char[50];
	strcpy_s(name,50,studentName);
	age = studentAge;
	for (int i = 0; i < 5; i++)
	{
		grades[i] = studentGrades[i];
	}
}

void Student::setName(const char* newName)
{
	strcpy_s(name,50,newName);
}

void Student::getName(char* outName)
{
	strcpy_s(outName,50, name);
}

void Student::setAge(int newAge)
{
	age = newAge;
}

int Student::getAge()
{
	return age;
}

void Student::setGrade(int index, int value)
{
	if (index >= 0 && index < 5)
	{
		grades[index] = value;
	}
}

int Student::getGrade(int index)
{
	if (index >= 0 && index < 5)
	{
		return grades[index];
	}
	return -1;
}

double Student::getAverage()
{
	double sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += grades[i];
	}
	return sum/5.0;
}

bool Student::isExcellent()
{
	for (int i = 0; i < 5; i++)
	{
		if (grades[i] < 90)
		{
			return false;
		}
	}
	return true;
}*/

