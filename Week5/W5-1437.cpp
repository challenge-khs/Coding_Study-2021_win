#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, sum = 1;
	cin >> n;

	while (n >= 5)
	{
		sum = (sum * 3) % 10007;
		n -= 3;
	}
	sum = sum * n;
	cout << sum % 10007;
	return 0;
}
