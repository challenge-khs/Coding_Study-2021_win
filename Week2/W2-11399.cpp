#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> p;
	int n, cnt = 0, temp = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		p.push_back(t);
	}

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++)
	{
		temp = temp + p[i];
		cnt = cnt + temp;
	}

	cout << cnt << endl;
	return 0;
}
