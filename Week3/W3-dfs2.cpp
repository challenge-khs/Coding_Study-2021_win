#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vect = { 1,2,3,4,5,6 };
vector<int> used = { 0,0,0,0,0,0 };
int ans = 0;

void dfs(int lv, int sum)
{
	if (lv == 3) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		if (used[i] == 0) 
		{
			used[i] = 1;
			dfs(lv + 1, sum + vect[i]);
			used[i] = 0;
		}
		
	}
}

int main(void)
{
	dfs(0, 0);
	cout << ans;
	return 0;
}
