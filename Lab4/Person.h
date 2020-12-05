/*
Person - класс информационных объектов, каждый из которых хранит данные о персоне
*/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
private:
	int idP;
	int id;
	string month;
	string phone;
public:
	Person(int idP, int id, string month, string phone);
	Person(Person& person);
	Person();
	~Person();

	int getIdP();
	int getId();
	string getMonth();
	string getPhone();

	friend ostream& operator<<(ostream& cout, Person& person);
};

