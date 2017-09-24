/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : A - Angka Ajaib
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

long long dp[N], done[N], ten[N];
char s[N];
int cnt[15];

long long d[N][2];

int main() {
  ten[0] = 1;
  for (int i = 1; i < N; i++) ten[i] = ten[i-1] * 10 % mod;

  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    memset(d, 0, sizeof(d));
    memset(done, 0, sizeof(done));
    memset(cnt, 0, sizeof(cnt));

    int n, k;
    scanf("%d %d %s", &n, &k, s);
    for (int i = 0; i < k; i++) cnt[s[i] - '0']++;
    int ada = 0;
    for (int i = 0; i < 10; i++) if (cnt[i]) ada++;
    
    if (ada == 1) {
      d[0][0] = 1;
      for (int i = 1; i <= n; i++) {
        d[i][0] += d[i-1][0] * 9 + d[i-1][1] * 9;
        d[i][1] += d[i-1][0] + d[i-1][1];
        d[i][0] %= mod;
        d[i][1] %= mod;

        done[i] = done[i-1] * 10 % mod;
        if (i - k >= 0) {
          d[i][1] -= d[i-k][0];
          d[i][1] %= mod;

          done[i] += d[i-k][0];
          done[i] %= mod;
        }
      }
      long long ans = ten[n] - done[n];

      //printf("mengandung %lld\n", done[n]);
      ans %= mod;
      if (ans < 0) ans += mod;
      printf("%lld\n", ans);
      continue;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1] * 10 % mod;
      done[i] = done[i - 1] * 10 % mod;
      if (i - k >= 0) {
        dp[i] -= dp[i - k];
        dp[i] %= mod;

        done[i] += dp[i - k];
        done[i] %= mod;
      }
    }
    long long ans = ten[n] - done[n];
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }

  return 0;
}
