/*
PersonSBTree - ������� �������� �������� ������ Person.
�������� ����������� � ��������� ��������� ������ ������ (Search Binary Tree)
��� ��������� ������������������.
����������� �������� �������, ������ � �������� ��������-������ � �������� ������.
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

	PersonNode* root; // ������ ��������� ������ ������

public:
	PersonSBTree();
	~PersonSBTree();

	// ������� � ������ ����� �������, ������ ������� ������� �� ������� person
	// ���������� true � ������ ������� �������, � false, ���� ������ � ����� ������ � ������ ��� ����	
	bool insert(Person& person);
	bool insert1(Person& person);
	// ����������� ������� ������� � ������ � ������ root ����� ������� 
	bool insertPerson(PersonNode*& root, Person& person);
	bool insertPerson1(PersonNode*& root, Person& person);

	// ����� � ������ ������� �� ����� keyIdP 
	// ���������� 
	//   true � ������ ��������� ������, ��� ���� ����� �������� person ���������� ��������� ������;
	//   false, ���� ������� � ����� ������ � ������ �����������.	
	bool  search(int keyIdP, Person& person);

	// ����� � ������ ������ �� ����� keyId 
	// ���������� 
	//   true � ������ ��������� ������, ��� ���� ����� �������� person ���������� ��������� �������;
	//   false, ���� ������� � ����� ������ � ������ �����������.
	bool  search1(int keyId, Person& person);

	// ����������� ������� ������ � ������ � ������ root ������� � ������ keyIdP
	bool  searchPerson(PersonNode*& root, int keyIdP, Person& person);

	// ����������� ������� ������ � ������ � ������ root ������� � ������ keyId
	bool  searchPerson1(PersonNode*& root, int keyId, Person& person);

	// �������� � ������ ������� �� ����� keyIdP
	// ���������� 
	//   true � ������ ��������� �������� �������;
	//   false, ���� ������� ������ � ����� ������ � ������ �����������.	
	bool  erase(int keyIdP);

	// ����������� ������� ������ � �������� � ������ � ������ root ������� � ������ keyIdP
	bool  erasePerson(PersonNode*& root, int keyIdP);

	// ��������������� ������� �������� ������� �� ���. 
	//����������� � ������ �������� ������� � ����� ������������
	void  del(PersonNode*& r, PersonNode*& delnode);

	// ������� ��������� ������ 
	void clear();

	// ����������� ������� ������� ������ � ������ root
	void clearSBTree(PersonNode* root);

	friend ostream& operator<<(ostream& cout, PersonSBTree& personSBTree);

	ostream& print(ostream& cout, PersonNode* root);
};

