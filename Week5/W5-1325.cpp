#include <iostream>
#include <vector>
#include <queue>
#define MA 10001
using namespace std;

int n, m;
vector<int> adj[MA];

int bfs(int start)
{
	int visit[MA] = { 0 }, cnt = 0;
	queue<int> q;
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int len = adj[x].size();
		for (int i = 0; i < len; i++)
		{
			int next = adj[x][i];
			if (visit[next] == 0)
			{
				visit[next] = 1;
				q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	vector<int> temp;
	int max = -1;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> e >> s;
		adj[s].push_back(e);
	}
	for (int i = 1; i <= n; i++)
	{
		temp.push_back(bfs(i));
		if (temp[i-1] > max)
			max = temp[i-1];
	}
	for (int i = 0; i < n; i++)
	{
		if (temp[i] == max)
			cout << i + 1 << " ";
	}
	return 0;
}
