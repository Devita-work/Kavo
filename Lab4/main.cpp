/*******************************************************************
 Информационная система «Бухгалтерия 1Ц» рассчитывает начисление заработной
платы работников некоторого предприятия. О каждом начислении зарплаты данные
представлены следующим набором: уникальный идентификатор idP (порядковый номер начисления), 
табельный номер работника, месяц, год, начисленная сумма. Реализовать систему хранения данных о 
зарплате в виде бинарного дерева поиска, ключом
которого является idP. Обеспечить
а) добавление нового начисления с автоматическим присваиванием idP;
б) поиск начисления зарплаты по idP;
в) поиск всех начислений зарплаты определённого работника;
г) выдачу всего списка начислений, упорядоченных по idP;
д) удаление начисления по ключу;
е) построение другого бинарного дерева поиска, ключом которого является табельный номер, и выдача списка 
начисления, упорядоченного по табельным номерам.
Авор: А. Е. Анисимов
Дата: 02.11.2020
********************************************************************/

#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

#include "Person.h"
#include "PersonSBTree.h"

using namespace std;

int main()
{
	// Локализация по кириллице
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// ------ Формирование базы данных (бинарное дерево поиска) о персонах
	PersonSBTree dataBase;
	PersonSBTree dataBase1;

	// Вставка в базу данных объектов, созданных как локальные
	Person p1(1, 423, "Jan", "44-44-44");
	dataBase.insert(p1);
	dataBase1.insert1(p1);
	Person p2(2, 231, "Fab", "55-55-55");
	dataBase.insert(p2);
	dataBase1.insert1(p2);

	// Вставка в базу данных объектов, созданных в динамической памяти
	dataBase.insert(*new Person(3, 321, "Jan", "66-66-66"));
	dataBase1.insert1(*new Person(3, 321, "Jan", "66-66-66"));
	dataBase.insert(*new Person(4, 213, "May", "77-77-77"));
	dataBase1.insert1(*new Person(4, 213, "May", "77-77-77"));

	dataBase.insert(*new Person(5, 132, "Fab", "11-11-11"));
	dataBase1.insert1(*new Person(5, 132, "Fab", "11-11-11"));
	dataBase.insert(*new Person(6, 321, "May", "22-22-22"));
	dataBase1.insert1(*new Person(6, 321, "May", "22-22-22"));


	cout << "Сортировка по IdP:" << endl;
	cout << dataBase << endl;
	cout << "Сортировка по Id:" << endl;
	cout << dataBase1 << endl;

	// ------ Поиск в базе данных по ключу
	int key = 2; // 1500
	if (dataBase.search(key, p1)) {
		cout << "Поиск персоны с IdP = " << key << " успешен:" << endl;
		cout << p1 << endl << endl;
	}
	else
		cout << "Поиск персоны с IdP = " << key << " не успешен." << endl << endl;
	// Сортировка по Id
	cout << "Ключ - Id" << endl;
	cout << endl;
	cout << "Бухгалтерия 1Ц:" << endl;
	cout << dataBase1 << endl;

	key = 321;

	cout << "Поиск всех начислений персоны с Id = " << key << endl;
	if (dataBase1.search1(key, p1)) {
		cout << "успешен" << endl;
	}
	else
		cout << "не успешен" << endl;

		// ------ Удаление объекта из базы данных по ключу
	key = 2; // 1500
	if (dataBase.erase(key)) {
		cout << "Персона с IdP = " << key << " удалена:" << endl;
		cout << "Бухгалтерия 1Ц:" << endl;
		cout << dataBase;
	}
	else
		cout << "Удаляемая персона с IdP = " << key << " не обнаружена." << endl;
	cout << endl;

	dataBase.clear();
	dataBase1.clear();
	system("pause");
	return 0;
}
