#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	int al, bl, c, ans = 1e9;

	cin >> a >> b;
	al = a.length();
	bl = b.length();

	c = bl - al;

	for (int i = 0; i <= c; i++)
	{
		int cnt = 0;
		for (int j = 0; j < al; j++)
		{
			if (a[j] != b[j + i])
				cnt++;
		}

		if (cnt < ans)
			ans = cnt;
	}
	cout << ans;
	return 0; 
}
