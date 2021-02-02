#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	queue<int> q;
	vector<int> vect;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		vect.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < n; i++)
	{
		if (i < (n - 1))
			cout << vect[i] << ", ";
		else
			cout << vect[i] << ">";
	}
	return 0;
}
