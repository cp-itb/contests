/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : B
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ans[N];
int n, m, k;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    if (k < n) {
      memset(ans, -1, sizeof ans);
    }
    else {
      k -= n;
      int l = -1, c = 1;
      for (int i = 0; i < n; i++) {
        while (l < i && k < i-l-1) l++;
        if (l == -1) {
          if (c <= m)
            ans[i] = c++;
          else
            l++;
        }
        k -= i-l-1;
        if (l != -1) {
          ans[i] = ans[l++];
        }
      }
      if (k != 0)
        memset(ans, -1, sizeof ans);
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}
