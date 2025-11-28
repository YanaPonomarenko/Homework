/*#include <iostream>
using namespace std;


class Student
{
  char* name{ nullptr };
public:
  Student() = default;

  Student(const char* name)//обичний конструктор

  {
    setName(name);
  }
  //конструктор копіювання
  Student(const Student& other)
  {
    setName(other.name);
  }
  //конструктор переміщення
  Student(Student&& obj) noexcept
  {

    this->name = obj.name;
    obj.name = nullptr;

  }
  //оператор присвоєння копіювання
  Student& operator=(const Student& other)
  {
    if (this != &other)
    {
      setName(other.name);
    }
    return *this;
  }
  void setName(const char* name)
  {
    if (this->name)
    {
      delete[] this->name;
      this->name = nullptr;
    }
    if (name)
    {
      unsigned int len = strlen(name);
      this->name = new char[len + 1];
      strcpy_s(this->name, len + 1, name);
    }
  }

  ~Student()
  {
    if (name)
      delete[] name;
  }

};



void printName(const Student& stObj)
{
  cout << "Student name printed from function." << endl;
}

Student createStudent()
{
  bool flag = true;
  Student s1("Bob");
  Student s2("Alice");
  if (flag) return s1;  // NRVO(Named Return Value Optimization) не спрацює, потому что есть несколько объектов
  else return s2;
}

int main()
{
  Student st5("John");
  Student st6 = move(st5);//конструктор переміщення, повернений з функції
  Student st7 = st6;
  Student st4{ createStudent() };

  const unsigned int N = 30;
  char* name = new char[N];
  cout << "Enter student name: ";
  cin.getline(name, N);
  {
    Student st(name);
    printName(st);
    Student st2{ st };//конструктор копіювання
    Student st3;
    st3 = st2;//оператор копіювання
  }
  cout << name;
  delete[] name;

  return 0;
}*/