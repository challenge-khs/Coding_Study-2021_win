#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
	int y;
	int x;
	int cnt;
}Node;

int map[3][3] = { 0 };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main()
{
	int x1, x2, y1, y2;
	queue<Node> q;

	cin >> y1 >> x1;
	cin >> y2 >> x2;
	map[y1][x1] = 1;
	map[y2][x2] = 1;
	q.push({ y1,x1,1 });
	q.push({ y2,x2,1 });

	while (!q.empty())
	{
		Node t;
		t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && map[ny][nx] == 0)
			{
				q.push({ ny,nx,t.cnt + 1 });
				map[ny][nx] = t.cnt + 1;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
