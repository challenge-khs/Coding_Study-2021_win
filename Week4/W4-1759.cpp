#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int l, c;
char text[16];
int used[16];

void dfs(int now, int level)
{
	string ans = "";
	int mocnt = 0, jacnt = 0;
	if (level == l) {
		for (int i = 0; i < c; i++)
		{
			if (used[i] == 1)
			{
				ans += text[i];
				if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
					mocnt++;
				else
					jacnt++;
			}
		}
		if (mocnt > 0 && jacnt > 1)
			cout << ans << endl;
		return;
	}

	for (int i = now; i < c; i++)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			dfs(i, level + 1);
			used[i] = 0;
		}
	}
}

int main()
{
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> text[i];
	}

	sort(text, text + c);
	
	dfs(0, 0);
	return 0;
}
