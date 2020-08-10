/*
Input:
AABAABAACAABAAC
AABAAC
Output:
Index: 3
Index: 9
*/
#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
	int len = 0;
	lps[0] = 0;
	int i = 1;

	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string text, string pat)
{
	int M = pat.length();
	int N = text.length();

	int lps[M];
	computeLPSArray(pat, M, lps);
	/*for (int i = 0; i < M; ++i)
	{
		cout << lps[i] << " ";
	}*/
	int i = 0, j = 0;
	while (i < N)
	{
		if (pat[j] == text[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{
			cout << "Index: " << i - j << endl;
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != text[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i += 1;
		}
	}
}

int main()
{
	string text, pat;
	cin >> text >> pat;

	KMPSearch(text, pat);
}