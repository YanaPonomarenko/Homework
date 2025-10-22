#include "StudentHW.h"
#include <iostream>
using namespace std;

void StudentHW::input()
{
	cout << "ПІБ";
	cin.getline(full_name, 100);

	cout << "Дата народження";
	cin.getline(birth_date, 20);

	cout << "Контактний телефон";
	cin.getline(phone_number, 20);

	cout << "Місто";
	cin.getline(city, 50);

	cout << "Країна";
	cin.getline(country, 50);

	cout << "Навчальний заклад";
	cin.getline(institution_name, 100);

	cout << "Місто де знаходиться заклад";
	cin.getline(institution_city, 50);

	cout << "Країна де знаходиться заклад";
	cin.getline(institution_country, 50);

	cout << "Номер групм";
	cin.getline(group_number, 20);

}

void StudentHW::output()
{
	cout << "\nДані студента:\n";
	cout << "ПІБ: " << full_name << endl;
	cout << "Дата народження: " << birth_date << endl;
	cout << "Телефон: " << phone_number << endl;
	cout << "Місто: " << city << endl;
	cout << "Країна: " << country << endl;
	cout << "Навчальний заклад: " << institution_name << endl;
	cout << "Місто де знаходиться заклад: " << institution_city << endl;
	cout << "Країна де знаходиться заклад: " << institution_country << endl;
	cout << "Група: " << group_number << endl;
}
