/**
 * Contest : COMPFEST 2017 Practice Session Final
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : A - Restoran Chanek
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int v;
        scanf("%d", &v);
        ans += v;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
