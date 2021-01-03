#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	char s[50][50];

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> s[i][j];
	}

	for (int k = 0; k <= n / 2; k++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (s[i + 1][j] == '_')
				{
					s[i + 1][j] = s[i][j];
					s[i][j] = '_';
				}
			}
		}
	}

	/*cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << s[i][j];
		cout << "\n";
	}*/

	for (int k = 0; k <= n / 2; k++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (s[i + 1][j] == s[i][j])
				{
					s[i + 1][j] = '_';
					s[i][j] = '_';
				}
				else if (s[i + 1][j] == '_')
				{
					s[i + 1][j] = s[i][j];
					s[i][j] = '_';
				}
			}
		}
	}

	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << s[i][j];
		cout << "\n";
	}
}
