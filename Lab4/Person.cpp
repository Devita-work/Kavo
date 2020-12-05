#include "Person.h"

Person::Person(int idP, int id, string month, string phone)
{
	this->idP = idP;
	this->id = id;
	this->month = month;
	this->phone = phone;
}

Person::Person(Person& person)
{
	this->idP = person.idP;
	this->id = person.id;
	this->month = person.month;
	this->phone = person.phone;
}

Person::Person()
{
	this->idP = 0;
	this->id = 0;
	this->month = "";
	this->phone = "";
}

Person::~Person()
{
}

int Person::getId()
{
	return id;
}

string Person::getMonth()
{
	return month;
}

int Person::getIdP()
{
	return idP;
}

string Person::getPhone()
{
	return phone;
}

ostream& operator<<(ostream& cout, Person& person)
{
	return cout
		<< setw(10) << person.idP
		<< setw(12) << person.id
		<< setw(12) << person.month
		<< setw(10) << person.phone;
}


