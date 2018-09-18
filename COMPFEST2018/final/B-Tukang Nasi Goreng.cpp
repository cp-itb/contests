/**
 * Contest : COMPFEST 2018 Final
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : B - Fenomena KPK   
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

int ans[N];

int fp[N];
int pw[N];
int last[N];

int main() {
  for (int i = 0; i < N; ++i)
    ans[i] = N + N;
  for (int i = 2; i < N; ++i) {
    if (fp[i]) continue;
    for (int j = i; j < N; j += i)
      if (fp[j] == 0)
        fp[j] = i;
  }
  int now = 2;
  for (int i = 1; i < N; ++i) {
    int cur = i;
    while (cur > 1) {
      int p = fp[cur], pp = 1;
      while ((cur % p) == 0) {
        cur /= p;
        pp *= p;
      }
      now = max(now, i+pp);
    }
    ans[i] = now;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  return 0; 
}
