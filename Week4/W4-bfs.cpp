#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node {
	int y, x;
	int cnt;
}Node;

int map[5][5] = { 0 };
int direct[4][2] = { 1,0,-1,0,0,1,0,-1 };
// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};

void print() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << map[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(void) {

	vector<Node> que = { {2,2, 0} };
	map[2][2] = -1;
	int head = 0; int tail = 1;
	while (head != tail) { // q.size(), !q.empty()
		Node now = que[head];

		for (int i = 0; i < 4; ++i) {

			// 다음으로 이동할 위치를 새로 만들어 준다. 포문이 돌때마다 4방으로 이동한다.
			int y_pos = now.y + direct[i][0];
			int x_pos = now.x + direct[i][1];

			// 맵의 범위안에 들어가 있으며, 사용하지 않은 곳에만 들어간다.
			if (0 <= y_pos && y_pos < 5 && 0 <= x_pos && x_pos < 5 && map[y_pos][x_pos] == 0) {
				map[y_pos][x_pos] = now.cnt + 1;
				que.push_back({ y_pos, x_pos, now.cnt + 1 }); tail++; // q.push 같은것이다.
			}
		}

		head++;
	}
	print();
	cout << que.back().cnt;
	return 0;
}
