/*
Input:
                  20
                /    \
              8       22
            /   \    /   \
          5      3 4     25
                / \
              10    14
Output:
LeftView:
20 8 5 10
RightView:
20 22 25 14
TopView:
5 8 20 22 25
BottomView Right Preference:
5 10 4 14 25
BottomView Left Preference:
5 10 3 14 25
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

void bottomViewL(node *root) {
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

		if (t->right)
			q.push(make_pair(t->right, hd + 1));
		if (t->left)
			q.push(make_pair(t->left, hd - 1));
	}
	for (auto i = m.begin(); i != m.end(); ++i)
		cout << i->second << " ";
}

int main() {
	node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(5);
	root->left->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(25);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	cout << "LeftView:\n";
	leftView(root);
	cout << endl;

	cout << "RightView:\n";
	rightView(root);
	cout << endl;

	cout << "TopView:\n";
	topView(root);
	cout << endl;

	cout << "BottomView Right Preference:\n";
	bottomViewR(root);
	cout << endl;

	cout << "BottomView Left Preference:\n";
	bottomViewL(root);
	cout << endl;
}
