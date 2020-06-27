/**
 * Contest : COMPFEST 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : E
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    double ans = (double) m * m / n;
    printf("%.15f\n", ans);
  }

  return 0;
}