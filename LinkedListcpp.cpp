#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) 
        {
            data = value;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;

public:
    LinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() 
    {
        DeleteAll();
    }

    void AddToHead(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!tail) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() 
    {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    void DeleteFromTail() 
    {
        if (!tail) return;

        if (head == tail) 
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next != tail) 
        {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void DeleteAll() 
    {
        while (head) 
        {
            DeleteFromHead();
        }
    }

    void Show() 
    {
        if (!head) 
        {
            cout << "Список пустий" << endl;
            return;
        }

        Node* current = head;
        while (current) 
        {
            cout << current->data;
            if (current->next) cout << " - ";
            current = current->next;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, " ");
    LinkedList<int> list;

    cout << "Додаємо елемент у голову: " << endl;
    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);
    list.Show();

    cout << "Додаємо едемент у хвіст:" << endl;
    list.AddToTail(4);
    list.AddToTail(5);
    list.Show();

    cout << "Видаляємо елемени з голови" << endl;
    list.DeleteFromHead();
    list.Show();

    cout << "Видаляємо елемент з хвоста" << endl;
    list.DeleteFromTail();
    list.Show();

    cout << "Очищаємо список" << endl;
    list.DeleteAll();
    list.Show();

    return 0;
}