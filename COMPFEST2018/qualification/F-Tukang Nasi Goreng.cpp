/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : F - Jelajah Kota 
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 2048;
const long long inf = 1e18;

int c[N], d[N], r[N];
long long dp[N][N][2];
long long x[N];

void upd(long long & var, long long val) {
  if (var < val)
    var = val;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    for (int i = 0; i < n; ++i)
      scanf("%d", c+i);
    for (int i = 0; i < n; ++i)
      scanf("%d", r+i);
    for (int i = 0; i + 1 < n; ++i)
      scanf("%d", d+i);
    long long ans = 0;
    for (int z = 0; z < 2; ++z) {
      x[0] = 0;
      for (int i = 0; i + 1 < n; ++i)
        x[i+1] = x[i] + d[i];
      for (int j = 1; j <= k; ++j)
        for (int i = 0; i < n; ++i)
          dp[j][i][0] = dp[j][i][1] = -inf;
      for (int i = 0; i < n; ++i) {
        dp[1][i][0] = r[i];
        dp[1][i][1] = r[i] - c[i];
      }
      for (int j = 1; j < k; ++j) {
        deque<pair<long long, int> > one, zero, ch;
        for (int i = 0; i < n; ++i) {
          while (!zero.empty() && x[i] - x[zero.front().second] > l) zero.pop_front();
          while (!one.empty() && x[i] - x[one.front().second] > l) one.pop_front();
          while (!ch.empty() && x[i] - x[ch.front().second] > l) ch.pop_front();
          if (!zero.empty()) {
            upd(dp[j+1][i][0], zero.front().first - 2LL * x[i]+ r[i]);
          }
          if (!one.empty()) {
            upd(dp[j+1][i][1], one.front().first - x[i] + r[i]);
          }
          if (!ch.empty()) {
            upd(dp[j+1][i][1], ch.front().first - 2LL * x[i] + r[i] - c[i]);
          }
          long long cur = dp[j][i][0] + 2LL * x[i];
          while (!zero.empty() && zero.back().first <= cur) zero.pop_back();
          zero.push_back(make_pair(cur, i));
          cur = dp[j][i][1] + x[i];
          while (!one.empty() && one.back().first <= cur) one.pop_back();
          one.push_back(make_pair(cur, i));
          cur = dp[j][i][0] + 2LL * x[i];
          while (!ch.empty() && ch.back().first <= cur) ch.pop_back();
          ch.push_back(make_pair(cur, i));
        }
      }
      for (int j = 1; j <= k; ++j)
        for (int i = 0; i < n; ++i)
          upd(ans, dp[j][i][1]);
      reverse(c, c+n);
      reverse(r, r+n);
      reverse(d, d+n-1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
