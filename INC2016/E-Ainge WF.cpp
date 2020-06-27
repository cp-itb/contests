/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : E - Legendary Dance
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N], b[N];
int dp[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(dp, 0, sizeof(dp));
    
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < m; i++) scanf("%d", b + i);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        if (a[i] == b[j]) {
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
      }
    }
    int ans = n + m - dp[n][m];
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}