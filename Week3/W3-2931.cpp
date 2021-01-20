#include <iostream>
#include <string>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);

	string s;
	int cnt = 0, len;

	cin >> s;
	len = s.size();

	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == '=')
		{
			if (s[i - 1] == 'z')
			{
				cnt++;
				i--;
				if (s[i - 1] == 'd')
					i--;
			}
			else if (s[i - 1] == 'c' || s[i - 1] == 's')
			{
				cnt++;
				i--;
			}
		}
		else if (s[i] == '-')
		{
			if (s[i - 1] == 'c' || s[i - 1] == 'd')
			{
				cnt++;
				i--;
			}
		}
		else if (s[i] == 'j')
		{
			cnt++;
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
				i--;
		}
		else
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
