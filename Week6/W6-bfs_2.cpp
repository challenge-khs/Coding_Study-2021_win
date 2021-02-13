#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
	int y;
	int x;
	int cnt;
}Node;

int map[4][4] = { 0,0,0,0,1,1,0,1,0,0,0,0,1,0,1,0 };
int visit[4][4] = { 0 };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int xs, xe, ys, ye;
queue<Node> q;

int bfs()
{
	q.push({ ys,xs,0 });

	while (!q.empty())
	{
		Node t;
		t = q.front();
		q.pop();

		if (t.x == xe && t.y == ye)
		{
			return map[t.y][t.x];
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[ny][nx] == 0 && visit[ny][nx] == 0)
			{
				q.push({ ny,nx,t.cnt + 1 });
				map[ny][nx] = t.cnt + 1;
				visit[ny][nx] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	int ans;
	cin >> ys >> xs;
	cin >> ye >> xe;

	ans = bfs();
	cout << ans;
	return 0;
}
