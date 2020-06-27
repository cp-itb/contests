/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Emeurgence
* Author  : donbasta
* Problem : E - Lucky Winner
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int N = 1e3 + 10;
const ll INF = 1e18;
 
ll min3(ll a, ll b, ll c) {
  return min(a, min(b, c));
}
 
ll min4(ll a, ll b, ll c, ll d) {
  return min(a, min3(b, c, d));
}
 
int n, kk;
ll ar[N][3];
ll DP[N][N];
ll dp[N][N][8];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
 
  cin >> n >> kk;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> ar[i][j];
      ar[i][j] = -ar[i][j];
    }
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= kk; j++) {
      DP[i][j] = INF;
      for(int k = 0; k < 8; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  for(int i = 0; i <= n; i++) {
    DP[i][0] = 0;
  }
  for(int i = 0; i <= n; i++)
    for(int j = 0; j < 8; j++){
      dp[i][0][j] = 0;
    }
  for(int i = 0; i <= kk; i++)
    for(int j = 0; j < 8; j++){
      dp[0][i][j] = 0;
    }
 
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= kk; j++) {
      dp[i][j][0] = DP[i - 1][j];
      if(i > 1) {
        dp[i][j][1] = min4(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2], dp[i - 1][j - 1][3], dp[i - 1][j - 1][6]) + ar[i][0] + ar[i - 1][0];
        dp[i][j][2] = min4(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][3], dp[i - 1][j - 1][5]) + ar[i][1] + ar[i - 1][1];
        dp[i][j][3] = min4(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2], dp[i - 1][j - 1][1], dp[i - 1][j - 1][4]) + ar[i][2] + ar[i - 1][2];
      }
      dp[i][j][4] = DP[i - 1][j - 1] + ar[i][0] + ar[i][1];
      if(j >= 2 && i >= 2)
        dp[i][j][4] = min(dp[i][j][4], min(dp[i - 1][j - 2][0], dp[i - 1][j - 2][3]) + ar[i][0] + ar[i][1] + ar[i - 1][0] + ar[i - 1][1]);
      if(j >= 2 && i >= 2)
        dp[i][j][5] = min(dp[i - 1][j - 2][0], dp[i - 1][j - 2][2]) + ar[i][0] + ar[i][2] + ar[i - 1][0] + ar[i - 1][2];
      dp[i][j][6] = DP[i - 1][j - 1] + ar[i][1] + ar[i][2];
      if(j >= 2 && i >= 2)
        dp[i][j][6] = min(dp[i][j][6], min(dp[i - 1][j - 2][0], dp[i - 1][j - 2][1]) + ar[i][2] + ar[i][1] + ar[i - 1][2] + ar[i - 1][1]);
      if(j >= 2 && i >= 2){
        dp[i][j][7] = min4(dp[i - 1][j - 2][0], dp[i - 1][j - 2][1], dp[i - 1][j - 2][2], dp[i - 1][j - 2][4]) + ar[i][0] + ar[i][1] + ar[i][2] + ar[i - 1][2];
        dp[i][j][7] = min(dp[i][j][7], min4(dp[i - 1][j - 2][0], dp[i - 1][j - 2][2], dp[i - 1][j - 2][3], dp[i - 1][j - 2][6]) + ar[i][0] + ar[i][1] + ar[i][2] + ar[i - 1][0]);
        dp[i][j][7] = min(dp[i][j][7], dp[i - 1][j - 3][0] + ar[i - 1][0] + ar[i - 1][1] + ar[i - 1][2] + ar[i][0]+ ar[i][1]+ ar[i][2]);      
      }
      for(int k = 0; k < 8; k++) {
        DP[i][j] = min(DP[i][j], dp[i][j][k]);
      }
    }
  }
 
  ll ans = -DP[n][kk];
  if(ans < 0) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}