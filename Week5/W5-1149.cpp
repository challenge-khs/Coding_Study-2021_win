#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int main()
{
	int n, ans = 9999999999;
    int house[MAX][4] = { 0 }, temp[MAX][4] = { 0 };
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> house[i][j];
            if (j == 1) {
                temp[i][j] = min(temp[i - 1][2], temp[i - 1][3]) + house[i][j];
            }
            else if (j == 2) {
                temp[i][j] = min(temp[i - 1][1], temp[i - 1][3]) + house[i][j];
            }
            else if (j == 3) {
                temp[i][j] = min(temp[i - 1][1], temp[i - 1][2]) + house[i][j];
            }
        }
    }
    for (int i = 1; i <= 3; i++)
        ans = min(ans, temp[n][i]);
    cout << ans;
	return 0;
}
