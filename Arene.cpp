#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Character {
public:
    virtual void attack() = 0;
    virtual void getInfo() = 0;
    virtual ~Character() {}
};

class Warrior : public Character 
{
    string name;
public:
    Warrior(const string& n) : name(n) {}

    void attack() override {
        cout << "Воїн " << name << " вдаряє мечем" << endl;
    }

    void getInfo() override {
        cout << "Воїн: " << name << endl;
    }
};

class Mage : public Character 
{
    string name;
public:
    Mage(const string& n) : name(n) {}

    void attack() override 
    {
        cout << "Маг " << name << " кидає вогняну кулю" << endl;
    }

    void getInfo() override 
    {
        cout << "Маг: " << name << endl;
    }
};

class Archer : public Character 
{
    string name;
public:
    Archer(const string& n) : name(n) {}

    void attack() override {
        cout << "Лучник " << name << " випускає стрілу" << endl;
    }

    void getInfo() override {
        cout << "Лучник: " << name << endl;
    }
};


class Arena 
{
    vector<Character*> fighters;
public:
    void addFighter(Character* fighter) 
    {
        fighters.push_back(fighter);
    }

    void removeFighter(int index) 
    {
        if (index >= 0 && index < fighters.size()) 
        {
            delete fighters[index];
            fighters.erase(fighters.begin() + index);
        }
    }

    void listFighters() 
    {
        cout << "Список бійців на арені: " << endl;
        for (size_t i = 0; i < fighters.size(); i++) 
        {
            cout << i + 1 << ". ";
            fighters[i]->getInfo();
        }
    }

    void startBattle() 
    {
        cout << "Битва ропочинається " << endl;
        for (auto fighter : fighters) 
        {
            fighter->attack();
        }
    }

    Arena operator+(Character* newFighter) 
    {
        this->addFighter(newFighter);
        return *this;
    }

    friend ostream& operator<<(ostream& os, Arena& arena) 
    {
        os << "Арена бійців" << endl;
        for (size_t i = 0; i < arena.fighters.size(); i++) 
        {
            os << "Боєць " << i + 1 << ": ";
            arena.fighters[i]->getInfo();
        }
        return os;
    }

    ~Arena() {
        for (auto fighter : fighters) 
        {
            delete fighter;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "");
   
    Arena arena;

    arena = arena + new Warrior("Тор");
    arena = arena + new Mage("Мерлін");
    arena = arena + new Archer("Леголас");
    arena = arena + new Warrior("Геракл");

    cout << arena;

    arena.startBattle();

    return 0;
}