/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : Berhitung
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ++n;
    vector<int> dp(2);
    dp[1] = 0;
    for (int k = 2; k <= n; k++) {
        int now = k % 2;
        int bfr = 1 - now;
        dp[now] = (dp[bfr] + n) % k;
    }
    cout << (dp[(n & 1)] + 1) << '\n';

    return 0;
}