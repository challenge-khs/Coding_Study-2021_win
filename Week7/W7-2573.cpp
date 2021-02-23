#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[301][301] = { 0, };
int visit[301][301] = { 0, };
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;

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
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny] == 0 && map[nx][ny] != 0)
			{
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
}

void melt()
{
	int melcnt;
	int temp[301][301] = { 0, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0)
			{
				melcnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (map[nx][ny] == 0 && nx >= 0 && nx < n && ny >= 0 && ny < m)
						melcnt++;
				}
				if (map[i][j] >= melcnt)
					temp[i][j] = map[i][j] - melcnt;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = temp[i][j];
			//cout << map[i][j] << " ";
		}
		//cout << "\n";
	}
}

int main()
{
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		int pcnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0 && visit[i][j] == 0)
				{
					bfs(i, j);
					pcnt++;
				}
			}
		}

		if (pcnt >= 2)
			break;

		melt();
		
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0)
					flag = 1;
			}
		}
		if (flag == 0)
		{
			ans = 0;
			break;
		}
		ans++;
	}
	cout << ans << "\n";
	return 0;
}
