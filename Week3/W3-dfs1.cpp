#include <iostream>
#include <vector>
using namespace std;

vector<int> tree = { -1,0,2,3,1,4,-1 };

void dfs(int now)
{
	if (now >= 7)
		return;
	if (tree[now] == -1)
		return;
	cout << tree[now];
	dfs(now * 2);
	dfs(now * 2 + 1);
}

int main(void)
{
	dfs(1);
	return 0;
}
