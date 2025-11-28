#include <iostream>
#include <exception>
#include <string>
using namespace std;

class NotEnoughFundsException : public exception 
{
    string message;
public:
    NotEnoughFundsException(const string& msg) : message(msg) {}

    const char* what() const noexcept override 
    {
        return message.c_str();
    }
};

class NegativeAmountException : public exception 
{
    string message;
public:
    NegativeAmountException(const string& msg) : message(msg) {}

    const char* what() const noexcept override 
    {
        return message.c_str();
    }
};

class BankAccount 
{
    string owner;
    double balance;
public:
    BankAccount(const string& o, double b) : owner(o), balance(b) {}

    void deposit(double amount) {
        if (amount <= 0) {
            throw NegativeAmountException("Помилка - сума поповнення має бути додатньою(" + to_string(amount) + ")");
        }
        balance += amount;
        cout << "Успішно поповнено на  " << amount << " грн. Оновлений баланс: " << balance << " грн" << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw NegativeAmountException("Помилка - сума зняття має бути додатньою(" + to_string(amount) + ")");
        }
        if (amount > balance) {
            throw NotEnoughFundsException("Помилка недостатньо коштів.Баланс: " + to_string(balance) + " грн, спроба зняти " + to_string(amount) + " грн");
        }
        balance -= amount;
        cout << "Успішно знято " << amount << " грн. Оновлений баланс: " << balance << " грн" << endl;
    }

    string getOwner() const { return owner; }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc("Іван", 200);

    cout << "Рахунок: " << acc.getOwner() << ", баланс: " << acc.getBalance() << " грн" << endl;

    try {
        acc.deposit(200);
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    try {
        acc.withdraw(100);
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    try {
        acc.withdraw(1000);
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    try {
        acc.deposit(-50);
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    cout << "Фінальний баланс: " << acc.getBalance() << " грн" << endl;

    return 0;
}