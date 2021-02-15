#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> arr(3);

int main() {
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> arr[i].first >> arr[i].second;

    for (int i = 0; i <= arr[0].first; i++) {
        int x = i;
        int ax = arr[0].first - x;
        int y = n - arr[2].first - arr[2].second - x;
        int by = arr[1].first - y;
        int z = arr[0].second - y;
        int cz = arr[2].first - z;

        if ((x >= 0) && (y >= 0) && (z >= 0) &&
            (ax >= 0) && (by >= 0) && (cz >= 0)) {
            cout << "1\n";
            cout << x << " " << ax << "\n";
            cout << y << " " << by << "\n";
            cout << z << " " << cz << "\n";
            return 0;
        }
    }
    cout << "0\n";

    return 0;
}
