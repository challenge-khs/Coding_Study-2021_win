#include <iostream>
#include <queue>
#define INF 9999
using namespace std;

int n, m;
int map[101][101], dist[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

typedef struct node
{
	int x, y, value;
};

int bfs()
{
	queue<node> q;
	dist[1][1] = 0;
	q.push({ 1,1,0 });
	while (!q.empty())
	{
		node t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if (nx >= 1 && nx <= m && ny >= 1 && ny <= n)
			{
				if (dist[nx][ny] > dist[t.x][t.y] + map[nx][ny]) {
					dist[nx][ny] = dist[t.x][t.y] + map[nx][ny];
					q.push({ nx, ny, -dist[nx][ny] });
				}
			}
		}
	}
	return dist[m][n];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%1d", &map[i][j]);
			dist[i][j] = INF;
		}
	}
	int ans = bfs();
	cout << ans << endl;
	return 0;
}
