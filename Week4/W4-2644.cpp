#include <iostream>

using namespace std;

int mem[101][101] = { 0 }, visit[101] = { 0 };
int n, a, b, m, ans = -1;

void dfs(int now, int cnt)
{
	if (now == b) {
		ans = cnt;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (mem[now][i] == 1 && visit[i] == 0)
		{
			visit[now] = 1;
			dfs(i, cnt + 1);
		}
	}
}

int main()
{
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		mem[t1][t2] = 1;
		mem[t2][t1] = 1;
	}

	dfs(a, 0);
	cout << ans;

	return 0;
}
