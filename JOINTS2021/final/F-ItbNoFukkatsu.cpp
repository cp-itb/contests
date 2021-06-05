 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Hasan
  * Problem : F
  */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, q;
int b[N];
int pre[N];
int l[N], r[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; i++) {
        pre[i] = (pre[i - 1] ^ b[i]);
    }
    for (int t = 1; t <= q; t++) {
        if (l[t] == r[t]) {
            cout << 0 << '\n';
            continue;
        }
        cout << (pre[r[t] - 1] ^ pre[l[t] - 1]) << '\n';
    }

    return 0;
}