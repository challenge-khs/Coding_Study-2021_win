#include <iostream>

using namespace std;

int main()
{
	int x, i;
	cin >> x;

	for (i = 1; x > 0; i++)
	{
		x = x - i;
	}

	if (i % 2 == 0)
	{
		cout << 1 - x << "/" << i + x - 1 << endl;
	}
	else
	{
		cout << i + x - 1 << "/" << 1 - x << endl;
	}

	return 0;
}
