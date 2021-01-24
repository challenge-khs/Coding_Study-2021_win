#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int t1;
	int t2;
}Node;

bool compare(Node a, Node b)
{
	if (a.t1 < b.t1)
		return true;
	else if (a.t1 == b.t1)
	{
		if (a.t2 < b.t2)
			return true;
		else if (a.t2 >= b.t2)
			return false;
	}
	else
		return false;
}


int main()
{
	//freopen("input.txt", "rt", stdin);

	int k;
	cin >> k;

	while (k--)
	{
		int n, cnt = 1;
		cin >> n;
		vector<Node> q(n);

		for (int i = 0; i < n; i++)
		{
			cin >> q[i].t1 >> q[i].t2;
		}

		sort(q.begin(), q.end(), compare);

		/*
		for (int i = 0; i < n; i++)
		{
			cout << q[i].t1 << " " << q[i].t2 << endl;
		}
		*/
		int temp = q[0].t2;
		for (int i = 1; i < n; i++)
		{
			if (temp > q[i].t2)
			{
				cnt++;
				temp = q[i].t2;
			}
		}
		cout << cnt << endl;
	}
}
