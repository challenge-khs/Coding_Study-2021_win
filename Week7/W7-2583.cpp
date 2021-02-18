#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k, cnt;
int arr[101][101] = { 0, }, visit[101][101] = { 0, };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	visit[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n)
		{
			if (arr[nx][ny] == 0 && visit[nx][ny] == 0)
				dfs(nx, ny);
		}
	}
}

int main()
{
	vector<int> ans;
	int len;

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
		{
			for (int l = x1; l < x2; l++)
			{
				arr[j][l] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && visit[i][j] == 0)
			{
				cnt = 0; 
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());
	len = ans.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
