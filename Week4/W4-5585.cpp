#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);

	int n, l, cnt = 0;
	cin >> n;
	n = 1000 - n;

	vector<int> coin = { 500,100,50,10,5,1 };
	l = coin.size();

	for (int i = 0; i < l; i++)
	{
		int temp = coin[i];
		cnt += n / temp;
		n %= temp; 
	}

	cout << cnt;
	return 0;
}
