#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
	int x;
	int y;
}node;

char map[251][251];
int visit[251][251];
int sheep = 0, wolf = 0, r, c;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int a, int b)
{
	int o = 0, v = 0;
	queue<node> q;
	q.push({ a,b });
	visit[a][b] = 1;

	while (!q.empty())
	{
		node t;
		t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c)
			{
				if (map[nx][ny] != '#' && visit[nx][ny] == 0)
				{
					visit[nx][ny] = 1;
					if (map[nx][ny] == 'o')
						o++;
					if (map[nx][ny] == 'v')
						v++;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (o > v)
		sheep += o;
	else
		wolf += v;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		getchar();
		for (int j = 0; j < c; j++)
		{
			scanf("%1c", &map[i][j]);
		}
	}
	/*
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			bfs(i, j);
		}
	}
	cout << sheep << " " << wolf;
	return 0;
}
