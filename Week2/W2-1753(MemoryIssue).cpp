#include <iostream>
#define INF 999999

using namespace std;

int v, e, k, a, b, w;
int graph[20001][20001];
bool visit[20001];
int d[20001];

int small_index()
{
	int min = INF;
	int index = 0;
	for (int i = 1; i <= v; i++)
	{
		if (d[i] < min && visit[i] == 0)
		{
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	for (int i = 1; i <= v; i++)
	{
		d[i] = graph[start][i];
	}
	visit[start] = true;
	for (int i = 1; i <= v - 2; i++)
	{
		int current = small_index();
		visit[current] = true;
		for (int j = 1; j <= v; j++)
		{
			if (visit[j] == 0)
			{
				if (d[current] + graph[current][j] < d[j])
					d[j] = d[current] + graph[current][j];
			}
		}
	}
}

int main()
{
	cin >> v >> e;
	cin >> k;

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}

	for (int i = 1; i <= e; i++)
	{
		cin >> a >> b >> w;
		graph[a][b] = w;
	}
	
	dijkstra(k);

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF)
			cout << "INF" << "\n";
		else
			cout << d[i] << "\n";
	}
	return 0;
}
