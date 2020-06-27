/**
 * Contest : COMPFEST 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : A
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
const double eps = 1e-11;

int a[N];
int n, k, m;

int can(double t) {
  int ret = 0;
  double now = m;
  for (int i = 0; i < n; i++) {
    now += a[i];
    if (now < t) return i;
    now -= t;
    if (now < eps) return i;
  }
  return inf;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &k, &m);
    k--;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    double l = 0, r = 4e9 + 5;
    for (int it = 0; it < 150; it++) {
      double mid = (l + r) / 2;
      //printf("%.15f %d\n", mid, can(mid));
      if (can(mid) > k) {
        l = mid;
      } else {
        r = mid;
      }
    }
    double ans = (double) r;
    if (can(r) != k) {
      puts("-1");
    } else {
      printf("%.15f\n", ans);
    }
  }

  return 0;
}