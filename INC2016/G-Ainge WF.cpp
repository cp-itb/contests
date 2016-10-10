/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : G - Beautiful Triple
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int a[N];
int cnt[N], last[N];
long long sum[N];

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
    }
    memset(cnt, 0, sizeof cnt);
    memset(sum, 0, sizeof sum);
    memset(last, 0, sizeof last);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      sum[a[i]] += 1LL * (i-last[a[i]]-1) * cnt[a[i]];
      sum[a[i]] %= mod;
      last[a[i]] = i;
      ans = (ans + sum[a[i]]) % mod;
      sum[a[i]] = (sum[a[i]] + cnt[a[i]]) % mod;
      cnt[a[i]]++;
    }
    if (ans < 0)
      ans += mod;
    printf("Case #%d: %lld\n", tt, ans);
  }
  return 0;
}