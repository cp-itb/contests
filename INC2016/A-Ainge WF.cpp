/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : A - String Matching
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N], p[N];

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    scanf("%s %s", p, s);
    int n = strlen(s), m = strlen(p);
    bool found = false;
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (j >= m) {
        found = true;
        break;
      }
      if (s[i] != p[j]) {
        j = 0;
      }
      else
        j++;
    }
    if (j >= m)
      found = true;
    printf("Case #%d: %s\n", tt, found ? "YES" : "NO");
  }
  return 0;
}