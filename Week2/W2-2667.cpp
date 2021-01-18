#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, id, map[25][25], visit[25][25], ans[(25 * 25) + 1];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	visit[x][y] = 1;
	ans[id]++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			if (map[nx][ny] == 1 && visit[nx][ny] == 0)
				dfs(nx, ny);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == 0)
			{
				id++;
				dfs(i, j);
			}
		}
	}

	sort(ans + 1, ans + id + 1);

	cout << id << endl;
	
	for (int i = 1; i <= id; i++)
	{
		cout << ans[i] << endl;
	}
	
}
