/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : J - Signal Strength
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int x[N], y[N], r[N];
int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%d %d", a+i, b+i);
    for (int i = 0; i < m; i++)
      scanf("%d %d %d", x+i, y+i, r+i);
    int ans = N;
    for (int i = 0; i < n; i++) {
      int now = 0;
      for (int j = 0; j < m; j++) {
        int dx = x[j]-a[i], dy = y[j]-b[i];
        int rr = dx * dx + dy * dy;
        if (rr <= r[j] * r[j])
          now++;
      }
      ans = min(ans, now);
    }
    printf("Case #%d: %d\n", tc, ans);

  }
  return 0;
}
