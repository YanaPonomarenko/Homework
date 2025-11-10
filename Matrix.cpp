#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Matrix 
{
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int r, int c);
    ~Matrix();

    void input();
    void fillRandom();
    T findMax();
    T findMin();

    Matrix operator+(const Matrix& obj);
    Matrix operator-(const Matrix& obj);
    Matrix operator*(const Matrix& obj);
    Matrix operator/(const T& number);

    void print() {
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

template <typename T>
Matrix<T>::Matrix() : rows(0), cols(0), data(nullptr) {}

template <typename T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c) 
{
    data = new T * [rows];
    for (int i = 0; i < rows; i++) 
    {
        data[i] = new T[cols];
    }
}

template <typename T>
Matrix<T>::~Matrix() 
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
void Matrix<T>::input() 
{
    cout << "Введіть " << rows << "x" << cols << " елементів\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cin >> data[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::fillRandom() 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            data[i][j] = rand() % 100;
        }
    }
}

template <typename T>
T Matrix<T>::findMax() 
{
    T max = data[0][0];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (data[i][j] > max) 
            {
                max = data[i][j];
            }
        }
    }
    return max;
}

template <typename T>
T Matrix<T>::findMin() 
{
    T min = data[0][0];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (data[i][j] < min) 
            {
                min = data[i][j];
            }
        }
    }
    return min;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& obj) 
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result.data[i][j] = data[i][j] + obj.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& obj) 
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result.data[i][j] = data[i][j] - obj.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& obj) 
{
    Matrix result(rows, obj.cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < obj.cols; j++) 
        {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; k++) 
            {
                result.data[i][j] += data[i][k] * obj.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T& number) 
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result.data[i][j] = data[i][j] / number;
        }
    }
    return result;
}
int main() 
{
    setlocale(LC_ALL, "");
    Matrix<int> mat1(2, 2);
    Matrix<int> mat2(2, 2);

    cout << "Заповнення матриць\n";
    cout << "Матриця(випадкові значення):\n";
    mat1.fillRandom();
    mat1.print();

    cout << "\nМатриця(введення з клавіатури):\n";
    mat2.input();
    mat2.print();

    cout << "\nАрифметичні операції\n";
    cout << "Додавання:\n";
    Matrix<int> sum = mat1 + mat2;
    sum.print();

    cout << "\nВіднімання:\n";
    Matrix<int> diff = mat1 - mat2;
    diff.print();

    cout << "\nМноження:\n";
    Matrix<int> mult = mat1 * mat2;
    mult.print();

    cout << "\nДілення на 2:\n";
    Matrix<int> div = mat1 / 2;
    div.print();

    cout << "\nПошук елементів\n";
    cout << "Максимальний елемент матриці 1: " << mat1.findMax() << endl;
    cout << "Мінімальний елемент матриці 1: " << mat1.findMin() << endl;

    return 0;
}