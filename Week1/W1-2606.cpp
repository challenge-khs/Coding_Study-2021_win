#include <iostream>

using namespace std;

int n, m, a, b;
int arr[101][101] = { 0 }, visit[101] = { 0 };
int cnt = 0;

void dfs(int now)
{
	visit[now] = 1;
	cnt++;
	for (int i = 1; i <= n; i++)
	{
		if (arr[now][i] == 1 && visit[i] == 0)
		{
			dfs(i);
		}
	}
}

int main() {
	cin >> n;
	cin >> m;	

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(1);
	cout << cnt - 1;
	return 0;
}
