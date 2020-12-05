/*
PersonSBTree - система хранения объектов класса Person.
Хранение реализовано в структуре бинарного дерева поиска (Search Binary Tree)
без поддержки сбалансированности.
Реализованы операции вставки, поиска и удаления объектов-вершин в бинарное дерево.
*/
#pragma once
#include "Person.h"

class PersonSBTree
{
private:
	struct PersonNode {
		Person person;
		PersonNode* left, * right;
		PersonNode(Person person, PersonNode* left, PersonNode* right) {
			this->person = person;
			this->left = left;
			this->right = right;
		}
		PersonNode() {
			this->person = person;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	PersonNode* root; // Корень бинарного дерева поиска

public:
	PersonSBTree();
	~PersonSBTree();

	// Вставка в дерево новой вершины, данные которой берутся из объекта person
	// Возвращает true в случае удачной вставки, и false, если объект с таким ключом в дереве уже есть	
	bool insert(Person& person);
	bool insert1(Person& person);
	// Рекурсивная функция вставки в дерево с корнем root новой вершины 
	bool insertPerson(PersonNode*& root, Person& person);
	bool insertPerson1(PersonNode*& root, Person& person);

	// Поиск в дереве вершины по ключу keyIdP 
	// Возвращает 
	//   true в случае успешного поиска, при этом через параметр person передается найденный объект;
	//   false, если вершина с таким ключом в дереве отсутствует.	
	bool  search(int keyIdP, Person& person);

	// Поиск в дереве вершин по ключу keyId 
	// Возвращает 
	//   true в случае успешного поиска, при этом через параметр person передается найденные объекты;
	//   false, если вершина с таким ключом в дереве отсутствует.
	bool  search1(int keyId, Person& person);

	// Рекурсивная функция поиска в дереве с корнем root вершины с ключом keyIdP
	bool  searchPerson(PersonNode*& root, int keyIdP, Person& person);

	// Рекурсивная функция поиска в дереве с корнем root вершины с ключом keyId
	bool  searchPerson1(PersonNode*& root, int keyId, Person& person);

	// Удаление в дереве вершины по ключу keyIdP
	// Возвращает 
	//   true в случае успешного удаления вершины;
	//   false, если вершина дерева с таким ключом в дереве отсутствует.	
	bool  erase(int keyIdP);

	// Рекурсивная функция поиска и удаления в дереве с корнем root вершины с ключом keyIdP
	bool  erasePerson(PersonNode*& root, int keyIdP);

	// Вспомогательная функция удаления вершины из БДП. 
	//Применяется в случае удаления вершины с двумя поддеревьями
	void  del(PersonNode*& r, PersonNode*& delnode);

	// Очистка бинарного дерева 
	void clear();

	// Рекурсивная функция очистки дерева с корнем root
	void clearSBTree(PersonNode* root);

	friend ostream& operator<<(ostream& cout, PersonSBTree& personSBTree);

	ostream& print(ostream& cout, PersonNode* root);
};

