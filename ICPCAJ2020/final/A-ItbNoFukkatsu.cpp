/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : A
 */
#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 1e3 + 10;
const int MX = 1e4 + 10;
const int INF = 1e9;
 
int n;
int ar[N], br[N]; // younger, older
 
int dp[N][2 * MX];
 
int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> br[i];
    }
    for (int i=0;i<N;i++){
        fill(dp[i], dp[i] + 2 * MX, INF);
    }
    dp[0][0] = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<MX;j++){
            if (dp[i][j] == INF) continue;
            dp[i + 1][j + br[i + 1]] = min(dp[i + 1][j + br[i + 1]], max(j + br[i + 1], dp[i][j]) + ar[i + 1]);
            if (i > 0 && i + 2 <= n){
                dp[i + 2][j + br[i + 2]] = min(dp[i + 2][j + br[i + 2]], max(j + br[i + 2], dp[i][j] + ar[i + 1]) + ar[i + 2]);
            }
        }
    }
    int ans = INF;
    for (int i=0;i<MX;i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
 
    return 0;
}