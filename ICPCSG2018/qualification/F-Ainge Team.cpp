/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Wiwit Rifa'i
 * Problem : F - Modulo Data Structures
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, S = sqrt(N) + 1;

int s[N], p[S][S];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; ++i) {
    int t, a, b, c;
    scanf("%d %d", &t, &a);
    if (t == 1) {
      scanf("%d %d", &b, &c);
      if (b < S)
        p[b][a] += c;
      else {
        for (int j = a; j <= n; j += b)
          s[j] += c;
      }
    }
    else {
      int sum = s[a];
      for (int j = 1; j < S; ++j) {
        sum += p[j][a % j];
      }
      printf("%d\n", sum);
    }
  }

  return 0;
}
