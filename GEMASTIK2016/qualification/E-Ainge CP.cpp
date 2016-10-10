/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : E - Libur Tahun Baru
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e8;

int dp[N][N], all[N];
int n, s, p, k[N], v[N];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &n, &s, &p);
    for (int i = 1; i < n; i++)
      scanf("%d %d", k + i, v + i);
    memset(all, 0, sizeof all);
    for (int i = 0; i <= s; i++)
      dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= s; j++) {
        dp[i][j] = -1;
        if (j >= k[i]) {
          int res = dp[i-1][j-k[i]];
          if (res >= 0)
            dp[i][j] = max(dp[i][j], res + v[i]);
        }
        if (j >= p) {
          dp[i][j] = max(dp[i][j], all[j-p]);
        }
      }
      for (int j = 0; j <= s; j++)
        all[j] = max(dp[i][j], all[j]);
    }
    int ans = -1;
    for (int i = 0; i <= s; i++)
      ans = max(ans, dp[n-1][i]);
    printf("%d\n", ans);
  }
  return 0;
}