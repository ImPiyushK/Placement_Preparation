/*
O/p:
PreOrder:
10 12 13 14 11 15 16
PreOrder:
13 12 14 10 15 11 16
PreOrder:
13 14 12 15 16 11 10
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	node *left;
	int data;
	node *right;
};

void inOrder(node *root) {
	if (root == NULL)	return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);

}

void preOrder(node *root) {
	if (root == NULL)	return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);

}

void postOrder(node *root) {
	if (root == NULL)	return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";

}

node* newNode(int n)
{
	node *t = new node;
	t->data = n;
	t->right = t->left = NULL;

	return t;
}

int main() {
	node *root = NULL;
	root = newNode(10);
	root->right = newNode(11);
	root->left = newNode(12);
	root->left->left = newNode(13);
	root->left->right = newNode(14);
	root->right->left = newNode(15);
	root->right->right = newNode(16);

	cout << "PreOrder: \n";
	preOrder(root);
	cout << endl;

	cout << "PreOrder: \n";
	inOrder(root);
	cout << endl;

	cout << "PreOrder: \n";
	postOrder(root);
	cout << endl;
}