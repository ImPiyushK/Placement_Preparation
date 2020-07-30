/*
Output:
Left->Right:
10 11 12 13 14 15 16
Right->Left:
10 12 11 16 15 14 13
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

node* newNode(int n) {
	node *t = new node;
	t->data = n;
	t->left = NULL;
	t->right = NULL;

	return t;
}

void levelOrderLR(node *root) {

	if (!root)
		return;
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node *t = q.front();
		cout << t->data << " ";
		q.pop();

		if (t->left)
			q.push(t->left);
		if (t->right)
			q.push(t->right);
	}
}

void levelOrderRL(node *root) {

	if (!root)
		return;
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node *t = q.front();
		cout << t->data << " ";
		q.pop();

		if (t->right)
			q.push(t->right);
		if (t->left)
			q.push(t->left);
	}
}

int main() {
	node *root = NULL;
	root = newNode(10);
	root->left = newNode(11);
	root->right = newNode(12);
	root->left->left = newNode(13);
	root->left->right = newNode(14);
	root->right->left = newNode(15);
	root->right->right = newNode(16);

	cout << "Left->Right:\n";
	levelOrderLR(root);
	cout << endl;

	cout << "Right->Left:\n";
	levelOrderRL(root);
	cout << endl;
}
