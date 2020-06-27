/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : I
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int s[N], t, n, k;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
      scanf("%d", s+i);
    sort(s, s+n);
    int ans = 1e9 + 9;
    int w = n-k;
    for (int i = 0; i+w <= n; i++) {
      ans = min(ans, s[i+w-1] - s[i]);
    } 
    printf("%d\n", ans);
  }
  return 0;
}
