#include <iostream>

using namespace std;

int main()
{
	int a, b, t, gcd, lcm;
	
	cin >> a >> b;

	if (a > b)
	{
		t = b;
		b = a;
		a = t;
	}
	for (int i = 1; i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcd = i;
		}
	}
	lcm = (a * b) / gcd;

	cout << gcd << endl;
	cout << lcm;
	return 0;
}
