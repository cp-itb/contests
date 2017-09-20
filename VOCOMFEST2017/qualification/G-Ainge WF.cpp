/**
 * Contest : VOCOMFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : G - Wireless Internet Connection
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

bool can(long long low, int u, long long hi, int v) {
  long long slope_a = hi - low;
  long long slope_b = abs(u - v);
  
  bool halang = 0;
  if (u < v) {
    for (int i = u + 1; i < v; i++) {
      if (slope_a > a[i] * slope_b / abs(i - u)) continue;
      long long lef = low * slope_b + abs(i - u) * slope_a;
      long long rig = a[i] * slope_b;
      if (lef <= rig) {
        halang = 1;
        break;
      }
    }
  } else {
    for (int i = u - 1; i > v; i--) {
      if (slope_a > a[i] * slope_b / abs(i - u)) continue;
      long long lef = low * slope_b + abs(i - u) * slope_a;
      long long rig = a[i] * slope_b;
      if (lef <= rig) {
        halang = 1;
        break;
      }
    }
  }
  return !halang;
}

int n, u, v;

bool can(long long t) {
  if (u == v) return 1;
  if (t < a[v]) {
    return can(t, u, a[v], v);
  } else {
    return can(a[v], v, t, u);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d %d %d", &n, &u, &v);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    can(0);
    
    long long l = 0, r = 1e14 + 5;
    
    while (l < r) {
      //printf("%lld %lld\n", l, r);
      long long mid = (l + r) >> 1;
      if (can(a[u] + mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    
    printf("Case #%d: %lld\n", tt, l);
  }
  return 0;
}
