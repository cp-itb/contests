/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : D - Amazing Restaurant
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = 1e9;

int a[N][3];
bool good[N][3];
int dp[N][3];

void upd(int& at, int val) {
  at = min(at, val);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(good, 0, sizeof(good));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 3; j++) {
        dp[i][j] = inf;
      }
    }

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 0; i < 3; i++) {
      int v;
      scanf("%d", &v);
      while (v--) {
        int k;
        scanf("%d", &k);
        good[k][i] = 1;
      }
    }

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        if (good[i][j]) upd(dp[i+1][j], dp[i][j]);
        for (int k = 0; k < 3; k++) {
          upd(dp[i+1][k], dp[i][j] + a[i+1][k]);
        }
      }
    }
    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    printf("Case #%d: ", tt);
    if (ans > m) {
      puts("Petruk is starving");
    } else {
      printf("%d\n", ans);
    }
  } 

  return 0;
}
