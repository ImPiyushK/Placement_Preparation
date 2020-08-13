#include<iostream>
using namespace std;
#define ALPHABETS 26

struct node
{
	bool isWord;
	node *next[ALPHABETS];
};

node* newNode()
{
	node *t = new node;
	t->isWord = false;
	for (int i = 0 ; i < ALPHABETS ; ++i)
		t->next[i] = NULL;

	return t;
}

void insert(node* head, string key)
{
	for (int i = 0; i < key.length(); ++i)
	{
		if (head->next[key[i] - 'a'] == NULL)
			head->next[key[i] - 'a'] = newNode();

		head = head->next[key[i] - 'a'];
	}
	head->isWord = true;
}

bool search(node *head, string key)
{
	for (int i = 0; i < key.length(); ++i)
	{
		if (head->next[key[i] - 'a'] == NULL)
			return false;
		else
			head = head->next[key[i] - 'a'];
	}
	return head->isWord;
}

bool check(node *head)
{
	for (int i = 0; i < ALPHABETS; ++i)
	{
		if (head->isWord || head->next[i] != NULL)
			return false;
	}
	return true;
}

node* remove(node *head, string key, int i)
{
	if (head == NULL) return NULL;
	int index = key[i] - 'a';
	if (i == key.length())
	{
		head->isWord = false;
		if (check(head))
			return NULL;
		else
			return head;
	}
	else if (head->next[index] != NULL)
	{
		node * t = remove(head->next[index], key, i + 1);
		if (t == NULL && i > 0)
		{
			remove(head->next[index], key, i + 1);
			head->next[key[i] - 'a'] = NULL;
			if (check(head))
				return NULL;
			else
				return head;
		}
		else
			return head;
	}
	else
		return NULL;
}

int main()
{
	node *head = newNode();
	int c;
	string key;
	do {
		cout << "\n1: Insert \n2: Search \n3:Delete\n4:Exit\n";
		cout << "Enter Choice: ";
		cin >> c;

		switch (c)
		{
		case 1:
			cin >> key;
			insert(head, key);
			break;
		case 2:
			cin >> key;
			if (search(head, key))
				cout << "Key Found" << endl;
			else
				cout << "Key Not Found" << endl;
			break;
		case 3:
			cin >> key;
			remove(head, key, 0);
			break;
		case 4:
			break;
		default:
			cout << "Wrong Choice";
		}

	} while (c != 4);
}