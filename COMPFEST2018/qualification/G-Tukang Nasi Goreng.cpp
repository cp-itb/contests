/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : G - FPB Terbesar 
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    memset(cnt, 0, sizeof cnt);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      ++cnt[a];
    }
    for (int i = 1; i < N; ++i) {
      for (int j = i+i; j < N; j += i)
        cnt[i] += cnt[j];
    }
    int ans = 1;
    for (int i = N-1; i > 0; --i) {
      if (cnt[i] >= m) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
