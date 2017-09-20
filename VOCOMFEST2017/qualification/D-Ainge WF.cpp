/**
 * Contest : VOCOMFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : D - Friends
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int dp[N+5][N+5], n, m;
int a[N], b[N], c[N];
vector< int > beg[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    memset(dp, 0, sizeof dp);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < N; i++)
      beg[i].clear();
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", a+i, b+i, c+i);
      beg[a[i]].push_back(i);
    }
    for (int i = 0; i+1 < N; i++) {
      for (int j = 0; j <= m; j++) {
        for (int id : beg[i]) if (j + c[id] <= m) {
          dp[b[id]+1][j+c[id]] = max(dp[b[id]+1][j+c[id]], dp[i][j] + 1);
        }
        dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
      }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
      ans = max(ans, dp[N-1][i]);
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
