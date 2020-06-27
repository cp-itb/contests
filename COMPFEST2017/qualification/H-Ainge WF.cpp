/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : H
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int cnt[256];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
      cnt[s[i]]++;
    }
    int ans = n;
    for (int i = 'a'; i <= 'z'; i++)
      ans = min(ans, n-cnt[i]);
    printf("%d\n", ans);
  }
  return 0;
}
