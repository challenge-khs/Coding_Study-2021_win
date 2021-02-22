#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int cnt0 = 0, cnt1 = 0, len, ans;
	cin >> s;

	len = s.length();

	if (s[0] == '0')
		cnt0++;
	else
		cnt1++;

	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] != s[i + 1])
		{
			if (s[i + 1] == '0')
				cnt0++;
			else
				cnt1++;
		}
	}
	ans = min(cnt0, cnt1);
	cout << ans;
	return 0;
}
