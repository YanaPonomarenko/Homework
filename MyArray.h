#pragma once
class MyArray
{
private:
	int* array;
	int size;
public:
	MyArray();
	MyArray(int* arr1, int size1);

	int* getArray();
	int getSize();

	void setArray(int* arr1, int size1);
	void setSize(int newSize);

	int getSum();
	void sortArray();
	int findIndex(int element);
	void printArray();

};

