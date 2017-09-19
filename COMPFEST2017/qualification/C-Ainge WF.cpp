/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : C
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long inf = 1e18;

int a[N][2], m, n;
long long dp[N][N][2];

int dist(int i, int j) {
  int d = abs(i - j);
  return min(d, m - d);
}

void upd(long long& at, long long val) {
  at = min(at, val);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j][0] = dp[i][j][1] = inf;
      }
    }
      
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i][0]);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i][1]);
      a[i][1] += m / 2;
      a[i][1] %= m;
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        //printf("%d %d %lld %lld\n", i, j, dp[i][j][0], dp[i][j][1]);
        if (i) assert(dp[i][j][0] != inf);
        if (j) assert(dp[i][j][1] != inf);
        if (i + 1 <= n) {
          upd(dp[i+1][j][0], dp[i][j][0] + dist(a[i][0], a[i+1][0]));
          upd(dp[i+1][j][0], dp[i][j][1] + dist(a[j][1], a[i+1][0]));
        }
        if (j + 1 <= n) {
          upd(dp[i][j+1][1], dp[i][j][0] + dist(a[i][0], a[j+1][1]));
          upd(dp[i][j+1][1], dp[i][j][1] + dist(a[j][1], a[j+1][1]));
        }
      }
    }
    printf("%lld\n", min(dp[n][n][0], dp[n][n][1]));
  }

  return 0;
}
