/*
Input:
5
A 3
B 5
C 6
D 4
E 2
Output:
D 00
E 010
A 011
B 10
C 11
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	char c;
	int f;
	node *left, *right;
};

node* newNode(char c, int f)
{
	node *t = new node();
	t->c = c;
	t->f = f;
	t->left = t->right = NULL;

	return t;
}

void heapify(node *minHeap[], int i, int n)
{
	int c1 = 2 * i + 1, c2 = 2 * i + 2;
	int min = i;

	if (c1 < n && minHeap[c1]->f < minHeap[min]->f)
		min = c1;
	if (c2 < n && minHeap[c2]->f < minHeap[min]->f)
		min = c2;

	if (min != i)
	{
		swap(minHeap[i], minHeap[min]);
		heapify(minHeap, min, n);
	}
}

node* extractMin(node *minHeap[], int &n)
{
	swap(minHeap[0], minHeap[n - 1]);
	n--;
	heapify(minHeap, 0, n);

	return minHeap[n];
}

void percolateUp(node* minHeap[], int i)
{
	int p = (i - 1) / 2;
	if (minHeap[p]->f > minHeap[i]->f)
	{
		swap(minHeap[p], minHeap[i]);
		percolateUp(minHeap, p);
	}
}

void insert(node* minHeap[], int &n, node* key)
{
	minHeap[n] = key;
	n++;
	percolateUp(minHeap, n - 1);
}

void minHeapify(node *minHeap[], int n)
{
	for (int i = n / 2 ; i >= 0 ; --i)
	{
		heapify(minHeap, i, n);
	}
}

void print(node *root, string s)
{
	if (root == NULL) return;
	if (root->c != '#') cout << root->c << " " << s << endl;
	print(root->left, s + "0");
	print(root->right, s + "1");
}

int main()
{
	int n;
	cin >> n;
	char c;
	int f;
	node *minHeap[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> f;
		minHeap[i] = newNode(c, f);
	}
	minHeapify(minHeap, n);

	while (n > 1)
	{
		node *l = extractMin(minHeap, n);
		node *r = extractMin(minHeap, n);
		node *t = newNode('#', l->f + r->f);
		t->left = l;
		t->right = r;

		insert(minHeap, n, t);
	}
	print(minHeap[0], "");
}
