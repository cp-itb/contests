/**
 * Contest : VOCOMFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : C - Batik Cap
 */

#include <bits/stdc++.h>

using namespace std;

char ans[55][55];
char s[10][55][55];
int m, n, r, c, p;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d %d %d %d %d", &p, &m, &n, &r, &c);
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < m; j++)
        scanf("%s", s[i][j]);
    }
    for (int i = 0; i < r; i += m) {
      for (int j = 0; j < c; j += n) {
        int now = (i/m + j/n) % p;
        for (int x = 0; x < m; x++)
          for (int y = 0; y < n; y++) {
            ans[i+x][j+y] = s[now][x][y];
          }
      }
    }
    printf("Case #%d:\n", tc);
    for (int i = 0; i < r; i++) {
      ans[i][c] = '\0';
      printf("%s\n", ans[i]);
    }
  }
  return 0;
}
