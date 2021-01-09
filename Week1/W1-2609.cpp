#include <iostream>

using namespace std;

int main()
{
	int a, b, t, gcd, lcm;
	
	cin >> a >> b;

	if (a > b)
	{
		t = a;
		b = a;
		a = t;
	}

	for (int i = 1; i <= b; i++)
	{
		if (a % i == 0 && b & i == 0)
		{

		}
	}
}
