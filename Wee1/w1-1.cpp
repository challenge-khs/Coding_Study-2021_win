#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main() {
    int arr[100], t1 = 0, t2 = 0, t3 = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            while (arr[i])
            {
                t1 += arr[i] % 10;
                arr[i] /= 10;
            }
        }
        t3 = 0;
        if (t1 >= 10)
        {
            while (t1)
            {
                t3 += t1 % 10;
                t1 /= 10;
            }
            t1 = t3;
        }
        t2 = 0;
        while (arr[i + 1])
        {
            t2 += arr[i + 1] % 10;
            arr[i + 1] /= 10;
        }
        //cout << t1 << " " << t2 << " t1 t2\n";
        t1 = t1 + t2;
        //cout << t1 << "  **\n";
    }
    cout << t1 << "\n";
}
