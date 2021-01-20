#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {
	int st;
	int fin;
}Node;

bool compare(Node a, Node b)
{
	if (a.fin < b.fin)
		return true;
	else if (a.fin == b.fin)
	{
		if (a.st < b.st)
			return true;
		else if (a.st >= b.st)
			return false;
	}
	else
		return false;
}

int main()
{
	//freopen("input.txt", "rt", stdin);

	int n, cnt = 1;
	cin >> n;
	vector<Node> q(n);

	for(int i = 0; i<n;i++)
	{
		cin >> q[i].st >> q[i].fin;
	}

	sort(q.begin(), q.end(), compare);
	/*
	for (int i = 0; i < n; i++)
	{
		cout << q[i].st << " " << q[i].fin << endl;
	}*/

	int time = q[0].fin;
	int endtime = q[n - 1].fin;

	for (int i = 1; i < n; i++)
	{
		if (time <= q[i].st)
		{
			cnt++;
			time = q[i].fin;
		}
	}

	cout << cnt;
	return 0;
}
