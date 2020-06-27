/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : E - Meja Putar
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main(){
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, pa, pb;
    scanf("%d %d %d", &n, &pa, &pb);
    int add = (n + pa - pb) % n, ans = 2 * n;
    bool first = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      if (i == 0)
        first |= pa == x;
      x--;
      a[x] = i; 
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", b+i);
      if (i == 0)
        first |= pb == b[i];
      b[i]--;
      b[i] = a[(b[i] + add) % n];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
      int p = lower_bound(a, a+k, b[i]) - a;
      a[p] = b[i];
      k += p == k;
    }
    ans -= k + first;
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
