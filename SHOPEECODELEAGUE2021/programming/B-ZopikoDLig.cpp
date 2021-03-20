/**
* Contest : Shopee Code League 2021
* Team    : ZopikoDLig
* Author  : Farras Faddila
* Problem : B
*/
#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 1000;
const int M = 1000;
 
ll ar[N + 10][M + 10];
 
int n, m;
 
void solve() {
    cin >> n >> m;
    vector<ll> kiri(n + 1), kanan(n + 1), total(n + 1);
    for (int i = 1; i <= n; i++) {
        kiri[i] = 0;
        kanan[i] = 0;
        for (int j = 1; j <= m; j++) {
            cin >> ar[i][j];
            total[i] += ar[i][j];
            kiri[i] = max(kiri[i], total[i]);
        }
        ll temp = 0;
        for (int j = m; j >= 1; j--) {
            temp += ar[i][j];
            kanan[i] = max(kanan[i], temp);
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[1][0] = kiri[1];
    dp[1][1] = total[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0] + kiri[i], dp[i - 1][1] + total[i]);
        dp[i][1] = max(dp[i - 1][1] + kanan[i], dp[i - 1][0] + total[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
 
    return 0;
}