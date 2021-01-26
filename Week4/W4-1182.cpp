#include <iostream>
#include <vector>
using namespace std;

vector<int> p;
int n, s, ans = 0;

void dfs(int now, int sum)
{
	if (now == n)
		return;
	if (sum + p[now] == s)
		ans++;

	dfs(now + 1, sum);
	dfs(now + 1, sum + p[now]);
}

int main()
{
	//freopen("input.txt", "rt", stdin);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		p.push_back(temp);
	}

	dfs(0, 0);
	cout << ans << endl;
}
