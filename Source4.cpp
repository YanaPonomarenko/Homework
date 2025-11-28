#include <iostream>
#include <string>
using namespace std;

class IPayment 
{
public:
    virtual void pay(double amount) = 0;
    virtual ~IPayment() {}
};

class CashPayment : public IPayment 
{
public:
    void pay(double amount) override 
    {
        cout << "Оплата готівкою " << amount << " грн" << endl;
    }
};

class CardPayment : public IPayment 
{
public:
    void pay(double amount) override 
    {
        cout << "Оплата картою" << amount << " грн" << endl;
    }
};

class ProductBase {
protected:
    string title;
    double price;
public:
    ProductBase(const string& t, double p) : title(t), price(p) {}

    virtual void showInfo() {
        cout << "Товар " << title << "ціна: " << price << " грн" << endl;
    }

    void pay(IPayment* paymentElement, double sum) 
    {
        if (paymentElement != nullptr) {
            cout << "Оплата за товар " << title << ": ";
            paymentElement->pay(sum);
        }
    }

    virtual ~ProductBase() {}
};

class OnlineStore : virtual public ProductBase 
{
public:
    OnlineStore(const string& t, double p) : ProductBase(t, p) {}

    void orderOnline() {
        cout << "Замовлення онлайн в магазині" << title << endl;
    }

    void showInfo() override {
        cout << "Онлайн магазин " << title << "ціна: " << price << " грн" << endl;
    }
};


class LocalStore : virtual public ProductBase 
{
public:
    LocalStore(const string& t, double p) : ProductBase(t, p) {}

    void sellOffline() {
        cout << "Продаж в офлайн магазині " << title << endl;
    }

    void showInfo() override {
        cout << "Локальний магазин " << title << "ціна: " << price << " грн" << endl;
    }
};

class HybridStore : public OnlineStore, public LocalStore 
{
public:
    HybridStore(const string& t, double p) :
        ProductBase(t, p),
        OnlineStore(t, p),
        LocalStore(t, p) {
    }

    void showInfo() override {
        cout << "Гібридний магазин" << title << "ціна: " << price << " грн" << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "");
    CashPayment cash;
    CardPayment card;

    HybridStore hybridStore("Comfy", 13000);
    hybridStore.showInfo();
    hybridStore.orderOnline();
    hybridStore.sellOffline();
    hybridStore.pay(&card, 13000);

    return 0;
}