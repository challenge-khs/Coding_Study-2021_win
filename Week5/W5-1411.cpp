#include <iostream>

using namespace std;

string s[100];

bool cmp(int a, int b)
{
	if (s[a].length() != s[b].length())
		return false;

	int check1[27] = { 0 }, check2[27] = { 0 }, len;
	len = s[a].length();

	for (int i = 0; i < len; i++)
	{
		int tmp1 = s[a][i] - 'a' + 1;
		int tmp2 = s[b][i] - 'a' + 1;
		if (check1[tmp1] == 0 && check2[tmp2] == 0)
		{
			check1[tmp1] = tmp2;
			check2[tmp2] = tmp1;
		}
		else if (check1[tmp1] != tmp2)
			return false;
	}
	return true;
}

int main()
{
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(i, j))
				ans++;
		}
	}
	cout << ans;
	return 0;
}
