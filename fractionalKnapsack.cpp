/*
Input:
4
100 10
40 2
120 30
60 10
20

Output:
188
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<double, pair<int, int> > a, pair<double, pair<int, int> > b)
{
	return a.first > b.first;
}

int factorialKnapsack(vector<pair<double, pair<int, int> > > items, int knapsack, int n)
{
	int p = 0;

	sort(items.begin(), items.end(), compare);

	for (int i = 0; i < n ; ++i)
	{
		if (items[i].second.second < knapsack)
		{
			knapsack -= items[i].second.second;
			p += items[i].second.first;
		}
		else
		{
			p += knapsack * items[i].first;
			knapsack = 0;
			break;
		}
	}
	return p;
}

int main()
{
	int n, knapsack;
	cin >> n;
	vector<pair<double, pair<int, int> > > items(n);
	for (int i = 0; i < n ; ++i)
	{
		cin >> items[i].second.first;
		cin >> items[i].second.second;

		items[i].first = (double)items[i].second.first / items[i].second.second;
	}
	cin >> knapsack;

	cout << factorialKnapsack(items, knapsack, n);
}