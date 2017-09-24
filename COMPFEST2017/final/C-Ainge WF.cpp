/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : C - Kuota Maksimum
 */

#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;
const long long N = 1e5 + 5;

long long dp[105][N];
int c[105], v[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j + c[i] <= m; j++) {
        dp[i][j + c[i]] = max(dp[i][j + c[i]], dp[i-1][j] + v[i]);
        dp[i][j + c[i]] = max(dp[i][j + c[i]], dp[i][j] + v[i]);
      }
      for (int j = 0; j <= m; j++) {
        dp[i][j] = max(dp[i][j], dp[i-1][j]);
      }
    }
    //printf("%d\n", dp[1][6]);
    long long ans = 0;
    for (int j = 0; j <= m; j++) ans = max(ans, dp[n][j]);
    printf("%lld\n", ans);
  }

  return 0;
}
