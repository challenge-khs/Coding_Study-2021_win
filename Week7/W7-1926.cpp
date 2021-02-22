#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[501][501] = { 0, };
int visit[501][501] = { 0, };
int n, m, pcnt = 0, mp = -1;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	int size = 1;

	visit[x][y] = 1;
	q.push({ x,y });

	while (!q.empty())
	{
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny] == 0 && map[nx][ny] == 1)
			{
				q.push({ nx,ny });
				visit[nx][ny] = 1;
				size++;
			}
		}
	}
	mp = max(mp, size);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == 0)
			{
				bfs(i, j);
				pcnt++;
			}
		}
	}
	if (mp < 0)
		mp = 0;
	cout << pcnt << "\n" << mp;
	return 0;
}
