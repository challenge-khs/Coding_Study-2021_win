#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[1001][1001];
int visit[1001];

void dfs(int now)
{
	visit[now] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (map[now][i] == 1 && visit[i] == 0)
		{
			dfs(i);
		}
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin);

	int u, v, cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
