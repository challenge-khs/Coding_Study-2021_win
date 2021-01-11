#include <iostream>

using namespace std;
# define M 1000001

int arr[M];
int n, m, o, a, b;

int find(int i)
{
	if (arr[i] == i)
		return i;
	else
		return arr[i] = find(arr[i]);
}

void uni(int f, int s)
{
	int firstParent = find(f);
	int secondParent = find(s);
	if (firstParent != secondParent)
		arr[firstParent] = secondParent;
}

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);*/

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	for(int i = 0; i < m; i++)
	{
		cin >> o >> a >> b;
		if (o == 0)
		{
			uni(a, b);
		}
		else
		{
			if (find(a) == find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
	return 0;
}

/*
void merge(int a, int b)
{
	arr[b] = arr[a];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	while(m--)
	{
		cin >> o >> a >> b;
		if (o == 0)
		{
			merge(a, b);
		}
		else if (o == 1)
		{
			if (arr[a] == arr[b])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
*/
