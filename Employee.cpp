#include <iostream>
#include <list>
#include <string>
using namespace std;

class Employee 
{
public:
    string name;
    float salary;

    Employee(string n, float s) : name(n), salary(s) {}
};

int main() {
    setlocale(LC_ALL, "");
    list<Employee> employees;

    employees.push_back(Employee("Employee1", 12000));
    employees.push_back(Employee("Employee2", 8500));
    employees.push_back(Employee("Employee3", 15000));
    employees.push_back(Employee("Employee4", 9500));
    employees.push_back(Employee("Employee5", 18000));

    int count = 0;
    for (const auto& emp : employees) 
    {
        if (emp.salary > 10000) 
        {
            count++;
        }
    }
    cout << "Робітники із зарплатою  > 10000: " << count << endl;

    bool swapped;
    do {
        swapped = false;
        auto it1 = employees.begin();
        auto it2 = employees.begin();
        if (it2 != employees.end()) it2++;

        while (it2 != employees.end()) 
        {
            if (it1->salary > it2->salary) 
            {
                swap(*it1, *it2);
                swapped = true;
            }
            it1++;
            it2++;
        }
    } while (swapped);

    cout << "\nСортування зарплати:" << endl;
    for (const auto& emp : employees) 
    {
        cout << emp.name << " " << emp.salary << endl;
    }

    if (!employees.empty()) 
    {
        auto max_it = employees.begin();
        auto it = employees.begin();
        it++;

        while (it != employees.end()) 
        {
            if (it->salary > max_it->salary) 
            {
                max_it = it;
            }
            it++;
        }
        cout << "\nРобітник із найвищою зарплатою: "
            << max_it->name << " " << max_it->salary << endl;
    }

    return 0;
}