/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : E - Mari Membaca 
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int h[N], t[N], v[N];
long long sum[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < n; ++i) {
      scanf("%d", h+i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", t+i), --t[i];
      sum[t[i]] += h[i];
    }
    for (int i = 0; i < m; ++i)
      scanf("%d", v+i);
    int ans = 0;
    long long cnt = 0;
    for (int i = 0; i < m; ++i) {
      long long cur = (sum[i] + v[i] - 1) / v[i];
      if (cur > cnt)
        ans = i, cnt = cur;
    }
    printf("%d\n", ans+1);
  }
  return 0;
}
