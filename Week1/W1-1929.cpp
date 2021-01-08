#include <iostream>

using namespace std;

int num[1000001];

int main()
{
	int m, n;

	cin >> m >> n;
	num[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (num[i] == 0)
		{
			for (int j = 2; n >= i * j; j++)
			{
				num[i * j] = 1;
			}
		}
	}
	for (int i = m; i <= n; i++)
	{
		if (num[i] == 0)
			cout << i << "\n";
	}
	return 0;
}

/*
#include <iostream>

using namespace std;

void test_number(int k)
{
	int d = 0;
	for (int j = 2; j < k; j++)
	{
		if (k % j == 0)
		{
			d = 1;
			break;
		}
	}
	if (d == 0)
		cout << k << "\n";
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = n; i <= m; i++)
	{
		test_number(i);
	}
}*/
