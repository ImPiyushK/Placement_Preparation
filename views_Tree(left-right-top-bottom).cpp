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

void leftView(node *root) {
	if (root == NULL)
		return;
	queue<pair<node*, int> > q;
	q.push(make_pair(root, 0));
	int depth = -1, cur_lvl = -1;

	while (!q.empty()) {
		node *t = q.front().first;
		cur_lvl = q.front().second;
		q.pop();

		if (cur_lvl > depth) {
			cout << t->data << " ";
			depth = cur_lvl;
		}
		if (t->left)
			q.push(make_pair(t->left, cur_lvl + 1));
		if (t->right)
			q.push(make_pair(t->right, cur_lvl + 1));
	}
}

void rightView(node *root) {
	if (root == NULL) return;

	queue<pair<node*, int> > q;
	q.push(make_pair(root, 0));
	int depth = -1;
	while (!q.empty()) {
		node *t = q.front().first;
		int cur_lvl = q.front().second;
		q.pop();

		if (cur_lvl > depth) {
			cout << t->data << " ";
			depth = cur_lvl;
		}

		if (t->right)
			q.push(make_pair(t->right, cur_lvl + 1));
		if (t->left)
			q.push(make_pair(t->left, cur_lvl + 1));
	}
}

void topView(node *root) {
	if (!root) return;

	map<int, int> m;
	m[0] = root->data;

	queue<pair<node*, int>> q;
	q.push(make_pair(root, 0));

	while (!q.empty()) {
		node *t = q.front().first;
		int hd = q.front().second;
		q.pop();

		if (m.find(hd) == m.end()) {
			m[hd] = t->data;
		}

		if (t->left)
			q.push(make_pair(t->left, hd - 1));
		if (t->right)
			q.push(make_pair(t->right, hd + 1));
	}
	for (auto it : m) {
		cout << it.second << " ";
	}
}

void bottomViewR(node *root) {
	if (!root) return;

	map<int, int> m;
	m[0] = root->data;

	queue<pair<node*, int>> q;
	q.push(make_pair(root, 0));

	while (!q.empty()) {
		node *t = q.front().first;
		int hd = q.front().second;
		q.pop();

		m[hd] = t->data;

		if (t->left)
			q.push(make_pair(t->left, hd - 1));
		if (t->right)
			q.push(make_pair(t->right, hd + 1));
	}
	for (auto i = m.begin(); i != m.end(); ++i)
		cout << i->second << " ";
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
	//root->left->left->left = newNode(18);
	root->right->right->right = newNode(17);

	cout << "LeftView:\n";
	leftView(root);
	cout << endl;

	cout << "RightView:\n";
	rightView(root);
	cout << endl;

	cout << "TopView:\n";
	cout << endl;

	cout << "BottomView:\n";
	cout << endl;
}
