#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct board {
	int x, y;
};

int l, s1, s2, e1, e2;
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
int ans[300][300];

void bfs()
{
	queue<board> q;
	q.push({ s1,s2 });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (x == e1 && y == e2) {
			cout << ans[x][y] << endl;
			return;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= l || ny < 0 || ny >= l)
				continue;
			if (ans[nx][ny])
				continue;
			ans[nx][ny] = ans[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}


int main()
{
	//freopen("input.txt", "rt", stdin);
	
	int test;
	cin >> test;

	while (test--)
	{
		cin >> l;
		cin >> s1 >> s2;
		cin >> e1 >> e2;
		bfs();
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}
