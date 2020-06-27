/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : E - Menginap
 */

#include <bits/stdc++.h>

using namespace std;


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      sum += r-l;
    }
    printf("%.1lf\n", (double)sum/2);
  }

  return 0;
}
