/**
 * Contest : GEMASTIK 2018 Qualification
 * Team    : Hikikomori
 * Author  : Wiwit Rifa'i
 * Problem : D1
 */

#include <bits/stdc++.h>

using namespace std;

int a[13][13];
int p[1000];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n-1; ++i) {
    a[0][i] = i+1;
  }
  a[0][n-1] = n * n;
  a[1][n-1] = n;
  a[1][n-2] = n * n - 1;
  for (int j = 2; j < n; ++j)
    a[j][n-1] = n * n - j;
  int z = 0;
  for (int i = n+1; i <= n * n - n; ++i) {
    p[z++] = i;
  }
  do {
    --k;
    for (int i = 0, x = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j])
          printf("%d%c", a[i][j], j == n-1 ? '\n' : ' ');
        else {
          assert(x < z);
          printf("%d%c", p[x++], j == n-1 ? '\n' : ' ');
        }
      }
    }
    if (k == 0)
      break;
  } while (next_permutation(p, p+z));
  return 0;
}
