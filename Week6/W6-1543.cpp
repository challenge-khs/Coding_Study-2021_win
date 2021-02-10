#include <iostream>
#include <string>

using namespace std;

int main()
{
	int len1, len2, cnt = 0;
	string s, cp;
	getline(cin, s);
	getline(cin, cp);

	len1 = s.size();
	len2 = cp.size();

	if (len2 > len1)
	{
		cout << cnt;
		return 0;
	}

	for (int i = 0; i < len1 - len2 + 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < len2; j++)
		{
			if (s[i + j] != cp[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			i = i + len2 - 1;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
