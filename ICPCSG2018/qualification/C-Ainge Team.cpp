/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Wiwit Rifa'i
 * Problem : C - Making Palindromes
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 202, mod = 1e9 + 7;

int dp[2][N][N];

char s[N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int n;
  scanf("%d %s", &n, s);
  int c = 0, b = 1;
  memset(dp, 0, sizeof dp);
  dp[c][0][n] = 1;
  for (int i = 0; i < n; ++i) {
    swap(c, b);
    memset(dp[c], 0, sizeof dp[c]);
    for (int l = 0; l < n; ++l) {
      add(dp[c][l][l], 1LL * dp[b][l][l] * 26 % mod);
      for (int r = l; r < n; ++r) {
        int now = dp[b][l][r+1];
        if (now == 0) continue;
        for (char k = 'A'; k <= 'Z'; ++k) {
          int ll = l, rr = r+1;
          if (s[r] == k) --rr;
          if (s[l] == k && ll < rr) ++ll;
          add(dp[c][ll][rr], now);
        } 
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    add(ans, dp[c][i][i]);
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}
