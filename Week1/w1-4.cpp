#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, k, temp = 0, arr[5][5], p[4];
	for (int i = 0; i < 4; i++)
	{
		p[i] = 0;
	}
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
			//temp[i][j] = arr[i][j];
		}
	}
	cin >> k;
	for (int z = 0; z < k; z++)
	{
		cin >> n >> m;

		n = n - 1;
		m = m - 6;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == m)
				{
					temp = arr[i][j];
					arr[i][j] = arr[j][n];
					arr[j][n] = temp;
				}
			}
		}
	}

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}*/

	temp = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < 2 && j < 2)
				p[0] += arr[i][j];
			else if (i < 2 && j > 2)
				p[1] += arr[i][j];
			else if (i > 2 && j < 2)
				p[2] += arr[i][j];
			else if (i > 2 && j > 2)
				p[3] += arr[i][j];
			else
				temp += arr[i][j];
		}
	}
	cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		p[i] += (temp / 4);
		cout << p[i] << " ";
	}
	cout << "\n";
}
