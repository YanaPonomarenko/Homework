#include <iostream>
#include "MyArray.h"
using namespace std;

MyArray::MyArray()
{
	array = nullptr;
	size = 0;
}

MyArray::MyArray(int* arr1, int size1)
{
	size = size1;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = arr1[i];
	}
}

int* MyArray::getArray()
{
	return array;
}

int MyArray::getSize()
{
	return size;
}

void MyArray::setArray(int* arr1, int size1)
{
	if (array != nullptr)
	{
		delete[] array;
	}
	size = size1;
	array = new int[size];

	for (int i = 0; i < 0; i++)
	{
		array[i] = arr1[i];
	}
}

void MyArray::setSize(int newSize)
{
	if (newSize <= 0)
	{
		return;
	}
	int* newArray = new int[newSize];

	for (int i = 0; i < newSize && i < size; i++) 
	{
		newArray[i] = array[i];
	}

	for (int i = size; i < newSize; i++) 
	{
		newArray[i] = 0;
	}
	if (array != nullptr) 
	{
		delete[] array;
	}

	array = newArray;
	size = newSize;
}

int MyArray::getSum()
{
	int sum = 0;
	for (int i = 0; i < size; i++) 
	{
		sum += array[i];
	}
	return sum;
}

void MyArray::sortArray()
{
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (array[j] > array[j + 1]) 
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int MyArray::findIndex(int element)
{
	for (int i = 0; i < size; i++) 
	{
		if (array[i] == element) 
		{
			return i;
		}
	}
	return -1;
}

void MyArray::printArray()
{
	cout << "Масив: [";
	for (int i = 0; i < size; i++) 
	{
		std::cout << array[i];
		if (i < size - 1) 
		{
			std::cout << ", ";
		}
	}
	cout << "]" <<endl;
}
