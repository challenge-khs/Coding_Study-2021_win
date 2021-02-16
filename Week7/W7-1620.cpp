#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	map<string, int> map1;
	map<int, string> map2;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		map1[input] = i;
		map2[i] = input;
	}
	for (int i = 0; i < m; i++)
	{
		string sear;
		cin >> sear;
		if (sear[0] >= '0' && sear[0] <= '9')
		{
			cout << map2[stoi(sear)] << "\n";
		}
		else
		{
			cout << map1[sear] << "\n";
		}
	}
	return 0;
}
