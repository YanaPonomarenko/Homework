#pragma once
class Student
{
private:
	char* name;
	int age;
	int grades[5];

public:
	Student();
	Student(const char* studentName, int studentAge, int studentGrades[5]);

	// сеттери геттери
	void  setName(const char* newName);
	void getName(char* outName);
	void setAge(int newAge);
	int getAge();
	void setGrade(int index, int value);
	int getGrade(int index);

	//методи
	double getAverage();
	bool isExcellent();
};

