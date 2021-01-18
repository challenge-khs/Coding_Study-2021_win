#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int direct[4][2] = { 1,0,0,1,-1,0,0,-1 };
typedef struct node {
    int y, x;
}Node;

int height, width;
int tail;
int ans = 0;
vector<Node> queue;
vector<vector<int>> map(8, vector<int>(8, 0));
vector<vector<int>> temp(8, vector<int>(8, 0));


void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void print(vector<vector<int>> temp) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << temp[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void bfs_fuction() {
    int head = 0; int t = tail;
    vector<Node> que = queue;
    vector<vector<int>> n = temp;
    while (head != t) {
        Node now = que[head];
        for (int i = 0; i < 4; ++i) {
            int y_pos = now.y + direct[i][0];
            int x_pos = now.x + direct[i][1];
            if (y_pos >= 0 && y_pos < height && x_pos >= 0 && x_pos < width && n[y_pos][x_pos] == 0) {
                n[y_pos][x_pos] = 2;
                que.push_back({ y_pos, x_pos }); t++;
            }
        }
        head++;
    }

    int virus = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (n[i][j] == 0) {
                ++virus;
            }
        }
    }
    //print(n);
    ans = max(virus, ans);
}

void run(int lv) {
    if (lv == 3) {
        bfs_fuction();
        return;
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (temp[i][j] == 0) {
                temp[i][j] = 1;
                run(lv + 1);
                temp[i][j] = 0;
            }
        }
    }
}

int main(void) {

    init();

    cin >> height >> width;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                queue.push_back({ i,j });
                tail++;
            }
        }
    }

    temp = map;

    run(0);
    cout << ans << "\n";
    return 0;
}
