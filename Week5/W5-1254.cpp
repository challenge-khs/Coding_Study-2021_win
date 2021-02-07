#include <iostream>
#include <string>

using namespace std;

string s;
int len;

bool check(int k)
{
	int half = (len - k) / 2;
	for (int i = 0; i < half; i++)
	{
		if (s[i + k] != s[len - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	int ans = 0;
	cin >> s;
	len = s.size();

	for (int i = 0; i < len; i++)
	{
		if (check(i))
		{
			ans = len + i;
			break;
		}
	}
	cout << ans;
	return 0;
}
