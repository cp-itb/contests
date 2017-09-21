/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : F - Road Trip
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long s[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", s + i);
  for (int i = 1; i <= n; i++) s[i] += s[i-1];
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    double ans = (double) (s[b] - s[a-1]) / (b - a + 1);
    printf("%.15f\n", ans);
  }
  return 0;
}
