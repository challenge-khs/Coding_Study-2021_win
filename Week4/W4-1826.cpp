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

bool operator<(gst a, gst b)
{
	if (a.dist < b.dist)
		return true;
	else
		return false;
}

int main()
{
	int n, l, p, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i].dist >> g[i].oil;
	}
	cin >> l >> p;

	sort(g, g + n, compare);

	int curl = p, curp = 0;
	priority_queue<int> pq;

	while (curl < l)
	{
		while (curp < n && g[curp].dist <= curl)
		{
			pq.push(g[curp++].oil);
		}
		if (pq.empty())
		{
			ans = -1;
			break;
		}
		curl += pq.top();
		pq.pop();
		ans++;
	}
	cout << ans << endl;
	return 0;
}
