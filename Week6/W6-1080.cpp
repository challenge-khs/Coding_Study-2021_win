#include <iostream>

using namespace std;

int mat1[50][50], mat2[50][50];
int n, m;

void rev(int a, int b)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (mat1[a + i][b + j] == 1)
				mat1[a + i][b + j] = 0;
			else
				mat1[a + i][b + j] = 1;
		}
	}
}

int main()
{
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &mat1[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &mat2[i][j]);
		}
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (mat1[i][j] != mat2[i][j])
			{
				rev(i, j);
				cnt++;
			}
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat1[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat2[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat1[i][j] != mat2[i][j])
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << cnt;
	return 0;
}
