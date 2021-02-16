#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int flag = 0;

bool compare(string a, string b)
{
	int al = a.size();
	int bl = b.size();
	if (al < bl)
		return true;
	else if (al == bl)
	{
		if (a < b)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	int n;
	cin >> n;
	vector<string> list;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		list.push_back(temp);
	}
	sort(list.begin(), list.end(), compare);
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
		{
			if (list[i] == list[i + 1])
			{
				continue;
			}
		}
		cout << list[i] << "\n";
	}
	return 0;
}
