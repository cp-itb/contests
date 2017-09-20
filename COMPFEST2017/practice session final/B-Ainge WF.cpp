/**
 * Contest : COMPFEST 2017 Practice Session Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : B - Palindromisme
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];
int cnt[256];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, ans = 0;
    scanf("%d %s", &n, s);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
      cnt[s[i]]++;
    }
    ans = n;
    for (int i = 0; i < 256; i++)
      ans = min(ans, n - cnt[i]);
    printf("%d\n", ans);
  }

  return 0;
}
