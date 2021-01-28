#include <iostream>
#include <string.h>
#include <queue>
#define INF 99999
using namespace std;

int n, m, ans, minvalue = 99999999;
int mem[101][101];
int dist[101];
queue<int> q;

void bfs(int start)
{
	dist[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		start = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (mem[start][i] == 1 && dist[i] == 0)
			{
				dist[i] = dist[start] + 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		mem[a][b] = 1;
		mem[b][a] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		memset(dist, 0, sizeof(dist));
		bfs(i);
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			else
				sum += (dist[j] - 1);
		}
		if (sum < minvalue)
		{
			minvalue = sum;
			ans = i;
		}
	}
	cout << ans;

	return 0;
}
