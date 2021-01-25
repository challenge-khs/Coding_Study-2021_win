#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visit[1000001];

int bfs()
{
	queue<int> q;
	q.push(S);
	visit[S] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == G)
			return visit[now] - 1;

		int next[2] = { now + U, now - D };
		for (int i = 0; i < 2; i++)
		{
			if (next[i] >= 1 && next[i] <= F && visit[next[i]] == 0)
			{
				visit[next[i]] = visit[now] + 1;
				q.push(next[i]);
			}
		}
	}
	return -1;
}

int main()
{
	cin >> F >> S >> G >> U >> D;

	int ans = bfs();
	if (ans == -1)
		cout << "use the stairs";
	else
		cout << ans;

	return 0;
}
