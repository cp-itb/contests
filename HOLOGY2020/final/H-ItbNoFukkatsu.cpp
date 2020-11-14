/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : H
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;
const ll INF = 1e18;
const int MASK = (1 << 3);

int n;
ll ar[N][3]; // col, row
ll dp[N][MASK][3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<3;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[j][i];
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<MASK;j++){
            for (int k=0;k<3;k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[1][1][0] = ar[1][0];
    for (int i=1;i<=n;i++){
        for (int j=0;j<MASK;j++){
            for (int k=0;k<3;k++){
                dp[i + 1][(1 << k)][k] = max(dp[i + 1][(1 << k)][k], dp[i][j][k] + ar[i + 1][k]);

                int nk;
                nk = k - 1;
                if (0 <= nk && nk < 3){
                    if ((j & (1 << nk)) == 0){
                        dp[i][j + (1 << nk)][nk] = max(dp[i][j + (1 << nk)][nk], dp[i][j][k] + ar[i][nk]);
                    }
                }
                nk = k + 1;
                if (0 <= nk && nk < 3){
                    if ((j & (1 << nk)) == 0){
                        dp[i][j + (1 << nk)][nk] = max(dp[i][j + (1 << nk)][nk], dp[i][j][k] + ar[i][nk]);
                    }
                }

                if (i < n){
                    if (k == 0 && j == (1 << k)){
                        ll cur = dp[i][j][k];
                        for (int jj=0;jj<3;jj++){
                            if (jj != k){
                                cur += ar[i][jj];
                            }
                            cur += ar[i + 1][jj];
                        }
                        dp[i + 1][MASK - 1][2] = max(dp[i + 1][MASK - 1][2], cur);
                    } else if (k == 2 && j == (1 << k)){
                        ll cur = dp[i][j][k];
                        for (int jj=0;jj<3;jj++){
                            if (jj != k){
                                cur += ar[i][jj];
                            }
                            cur += ar[i + 1][jj];
                        }
                        dp[i + 1][MASK - 1][0] = max(dp[i + 1][MASK - 1][0], cur);
                    }
                }
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=0;j<MASK;j++){
    //         for (int k=0;k<3;k++){
    //             cout << i << " " << j << " " << k << " " << dp[i][j][k] << el;
    //         }
    //     }
    // }
    ll ans = -INF;
    for (int i=0;i<MASK;i++){
        ans = max(ans, dp[n][i][2]);
    }
    cout << ans << el;

    return 0;
}