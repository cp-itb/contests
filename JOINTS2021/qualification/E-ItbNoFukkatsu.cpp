/**
  * Contest : Joints 2021 Qualification
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Kamal Shafi
  * Problem : E
***/
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 310;
const int MOD = 1e9 + 7;

int q;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i=1;i<=m;i++){
        dp[1][i] = 1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int ni=i + 1;ni<=min(n, i + 3);ni++){
                for (int nj=max(1, j - 3);nj<=min(m, j + 3);nj++){
                    if (nj == j) continue;
                    int del = abs(i - ni) + abs(j - nj);
                    if (del != 3) continue;
                    dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                }
            }
        }
    }
    int tot = 0;
    for (int i=1;i<=m;i++){
        tot = (tot + dp[n][i]) % MOD;
    }
    cout << tot << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}