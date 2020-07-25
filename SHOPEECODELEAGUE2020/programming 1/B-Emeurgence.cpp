/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Emeurgence
* Author  : Muhammad Hasan
* Problem : B - Judging Servers
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const long long INF = 1e18;

int tc;
int s, n;
int a[N];
long long dp[N][N];
long long pre[N][N];

void solve() {
    cin >> s >> n;
    for (int i = 1; i <= s; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= s - n + 1; i++) {
        dp[i][1] = (1LL) * a[i];
        if (i == 1) {
            pre[i][1] = dp[i][1];
        } else {
            pre[i][1] = min(pre[i - 1][1], dp[i][1]);  
        }
    }
    for (int j = 2; j <= n; j++) {
        for (int i = j; i <= s - n + j; i++) {
            dp[i][j] = min(dp[i][j], (1LL) * min(a[i], a[i - 1]) + pre[i - 2][j - 2]);
            dp[i][j] = min(dp[i][j], (1LL) * a[i] + pre[i - 1][j - 1]);
            if (i == j) {
                pre[i][j] = dp[i][j];
            } else {
                pre[i][j] = min(pre[i - 1][j], dp[i][j]);
            }
        }
    }
    cout << pre[s][n] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}