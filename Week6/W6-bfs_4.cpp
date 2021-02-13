#include <iostream>
#include <queue>

using namespace std;

int s, e;
int visit[201] = { 0 };

typedef struct node
{
	int x;
	int cnt;
}Node;

int ch(int a, int b)
{
	int t = a;
	if (b == 0 && t % 2 == 0)
		t = a / 2;
	else if (b == 1)
		t = a * 2;
	else if (b == 2)
		t = a + 1;
	else if (b == 3)
		t = a - 1; 
	return t;
}

int bfs()
{
	queue<Node> q;
	q.push({ s, 0 });
	visit[s] = 1;

	while (!q.empty())
	{
		Node t;
		t = q.front();
		q.pop();

		if (t.x == e)
		{
			return t.cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = ch(t.x, i);
			if (nx > 0 && nx < 200 && visit[nx] == 0)
			{
				q.push({ nx, t.cnt + 1 });
				visit[nx] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	int ans;
	cin >> s >> e;

	ans = bfs();

	cout << ans;
	return 0;
}
