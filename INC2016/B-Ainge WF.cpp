/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : B - Compact Bag
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int p = upper_bound(a, a + n, a[i] + k) - a;
      ans = max(ans, p - i);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}