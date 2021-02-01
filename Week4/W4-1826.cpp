#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct gst
{
	int dist, oil;
}gst;

gst g[10001];

bool compare(gst a, gst b)
{
	if (a.dist < b.dist)
		return true;
	else
		return false;
}

int main()
{
	int n, l, p, ans  = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i].dist >> g[i].oil;
	}
	cin >> l >> p;

	sort(g + 1, g + n + 1, compare);
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << g[i].dist << " " << g[i].oil << endl;
	}*/
	int curl = p, curp = 0;
	priority_queue<int> pq;

	while (curl < l)
	{
		while (curp < n && g[curp].dist <= p)
		{
			pq.push(g[curp++].oil);
		}
		if (pq.empty())
		{
			ans = -1;
			break;
		}
		curl += pq.top();
		pq.top();
		ans++;
	}
	cout << ans << endl;
	return 0;
}
