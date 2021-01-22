#include <iostream>
#include <string>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);

	string s;
	int value = 0, len;

	cin >> s;

	len = s.size();

	if (len % 3 == 1)
		cout << s[0];
	else if (len % 3 == 2)
		cout << (s[0] - '0') * 2 + (s[1] - '0');

	for (int i = len % 3; i < len; i += 3)
	{
		cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
	}

	return 0;
}
