/**
 * Contest : COMPFEST 2017 Practice Session Final
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : C - Iri Itu Tidak Baik
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int ans = 2e9;
    int num = n - k;
    for (int i = 0; i + num - 1 < n; i++) {
      ans = min(ans, a[i + num - 1] - a[i]);
    }
    printf("%d\n", ans);
  }

  return 0;
}
