#include <iostream>
#include <queue>

using namespace std;

int t, m, n, k, cnt = 0;
int map[50][50], visit[50][50];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int row, int col)
{
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visit[row][col] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 || nx > n || ny > m || ny <= 0)
			{
				if (map[nx][ny] == 1 && visit[nx][ny] == 0)
				{
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;
		if (map[ny][nx] == 1 && visit[ny][nx] == 0) {
			visit[ny][nx]++;
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int a, b;
			cin >> a >> b;
			map[b][a] = 1;
		}
		/*
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < m; q++)
			{
				cout << map[p][q] << " ";
			}
			cout << "\n";
		}*/
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < m; q++)
			{
				if (map[p][q] == 1 && visit[p][q] == 0)
				{
					dfs(p, q);
					//bfs(p, q);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < m; q++)
			{
				map[p][q] = 0;
				visit[p][q] = 0;
			}
		}
	}
	return 0;
}
