// 중복제거
#include <iostream>
#include <vector>
using namespace std;

vector<int> vect = { 1,2,3,4,5 };
vector<int> path;

void dfs(int lv, int now) {

	if (lv > 5) { return; }

	for (auto i : path) { cout << i; }
	cout << "\n";

	for (int i = now; i < 5; ++i) {
		path.push_back(vect[i]);
		dfs(lv + 1 , i);
		path.pop_back();
	}
}

int main(void) {
	dfs(0, 0);
	return 0;
}

