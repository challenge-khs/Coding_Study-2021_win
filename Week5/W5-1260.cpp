#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MA 1001
using namespace std;

int n, m;
int visit[MA];
vector<int> adj[MA];

void dfs(int start)
{
	visit[start] = 1;
	cout << start << " ";
	int len = adj[start].size();
	for (int i = 0; i < len; i++)
	{
		int next = adj[start][i];
		if (visit[next] == 0) {
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int x = q.front();
		cout << x << " ";
		q.pop();
		int len = adj[x].size();
		for (int i = 0; i < len; i++)
		{
			int next = adj[x][i];
			if (visit[next] == 0)
			{
				visit[next] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(v);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	bfs(v);
	return 0;
}
