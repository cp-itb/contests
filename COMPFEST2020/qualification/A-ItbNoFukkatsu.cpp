/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : A - Angka Cantik
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int M = 1e6;

int n;
long long m;
long long a[N];
vector<int> rem[M + 5];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<long long>());
    long long cur = 1;
    long long val = 0;
    for (int i = 1; i <= n; i++) {
        val = (val + a[n - i + 1] * cur) % m;
        cur = (cur * 10) % m;
    }
    if (val == 0) {
        for (int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << '\n';
        return 0;
    }
    rem[val].emplace_back(1);
    long long curval = val;
    for (int i = 2; i <= M; i++) {
        if (i * n > M) break;
        curval = (curval * cur + val) % m;
        rem[curval].emplace_back(i);
        if ((int) rem[curval].size() == 2) {
            int x = rem[curval][0], y = rem[curval][1];
            int dif = y - x;
            for (int it = 0; it < dif; it++) {
                for (int j = 1; j <= n; j++)
                    cout << a[j]; 
            }
            for (int it = 0; it < x; it++) {
                for (int j = 1; j <= n; j++)
                    cout << 0;
            }
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}