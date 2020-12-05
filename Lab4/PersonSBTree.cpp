#include "PersonSBTree.h"



PersonSBTree::PersonSBTree()
{
	root = nullptr;
}


PersonSBTree::~PersonSBTree()
{
	clear();
}

bool PersonSBTree::insert(Person& person)
{
	return insertPerson(root, person);
}

bool PersonSBTree::insertPerson(PersonNode*& root, Person& person)
{
	if (root == nullptr)
	{
		root = new PersonNode(person, nullptr, nullptr);
		return true;
	}
	else
	{
		if (person.getIdP() < root->person.getIdP())
			return insertPerson(root->left, person);
		else
			if (person.getIdP() > root->person.getIdP())
				return insertPerson(root->right, person);
			else
				return false;
	}
}


bool PersonSBTree::search(int keyIdP, Person& person)
{
	return searchPerson(root, keyIdP, person);
}

bool PersonSBTree::searchPerson(PersonNode*& root, int keyIdP, Person& person)
{
	if (root != nullptr)
	{
		if (root->person.getIdP() == keyIdP)
		{
			person = root->person;
			return true;
		}
		else
			if (keyIdP < root->person.getIdP())
				return searchPerson(root->left, keyIdP, person);
			else
				return searchPerson(root->right, keyIdP, person);
	}
	else
		return false;
}
bool PersonSBTree::search1(int keyId, Person& person)
{
	return searchPerson1(root, keyId, person);
}

bool PersonSBTree::searchPerson1(PersonNode*& root, int keyId, Person& person)
{
	if (root != nullptr)
	{
		if (root->person.getId() == keyId)
		{
			person = root->person;
			print(cout, root);

			return true;
		}
		else
			if (keyId < root->person.getId())
				return searchPerson1(root->left, keyId, person);
			else
				return searchPerson1(root->right, keyId, person);
	}
	return false;
}
bool PersonSBTree::insert1(Person& person)
{
	return insertPerson1(root, person);
}
bool PersonSBTree::insertPerson1(PersonNode*& root, Person& person)
{
	if (root == nullptr)
	{
		root = new PersonNode(person, nullptr, nullptr);
		return true;
	}
	else
	{
		if (person.getId() <= root->person.getId())
			return insertPerson1(root->left, person);
		else
			if (person.getId() > root->person.getId())
				return insertPerson1(root->right, person);

	}
}




ostream& operator<<(ostream& cout, PersonSBTree& personSBTree)
{
	cout << "--------------------------------------------" << endl;
	return 	personSBTree.print(cout, personSBTree.root)
		<< "--------------------------------------------" << endl;

}

bool PersonSBTree::erase(int keyIdP)
{
	return erasePerson(root, keyIdP);
}

bool PersonSBTree::erasePerson(PersonNode*& root, int keyIdP)
{
	//void DeleteNode(TreeNode * &p, int k)
	{
		PersonNode* delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (keyIdP < root->person.getIdP())
				return erasePerson(root->left, keyIdP);
			else
				if (keyIdP > root->person.getIdP())
					return erasePerson(root->right, keyIdP);
				else
				{
					delnode = root;
					if (delnode->right == nullptr)
						root = delnode->left;
					else
						if (delnode->left == nullptr)
							root = delnode->right;
						else
							del(delnode->left, delnode);
					delete delnode;
					return true;
				}
		}
	}
}

void  PersonSBTree::del(PersonNode*& r, PersonNode*& delnode)
{
	if (r->right)
		del(r->right, delnode);
	else
	{
		delnode->person = r->person;
		delnode = r;
		r = r->left;
	}
	return;
}

void PersonSBTree::clear()
{
	clearSBTree(root);
	root = nullptr;
	return;
}

void PersonSBTree::clearSBTree(PersonNode* root)
{
	if (root != nullptr)
	{
		clearSBTree(root->left);
		clearSBTree(root->right);
		delete root;
	}
	return;
}


ostream& PersonSBTree::print(ostream& cout, PersonNode* root)
{
	if (root)
	{
		print(cout, root->left);
		cout << root->person << endl;
		print(cout, root->right);
	}
	return cout;
}
