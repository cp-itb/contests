/**
 * Contest : GEMASTIK 2017 Pemanasan
 * Team    : Ainge ST
 * Author  : Luqman Arifin
 * Problem : C1 - Papan Selancar (Mudah)
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

long long a[N], b[N];
long long ca[N], cb[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(ca, 0, sizeof(ca));
    memset(cb, 0, sizeof(cb));

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int x, k;
      scanf("%d %d", &x, &k);
      a[x] += k;
      ca[x + 1]++;
      if (x + k + 1 < N) ca[x + k + 1]--;

      b[x - 1] += k - 1;
      if (x - 2 >= 0) cb[x - 2]++;
      if (x - k - 1 >= 0) cb[x - k - 1]--;
    }
    for (int i = 1; i < N; i++) {
      ca[i] += ca[i - 1];
      a[i] += a[i - 1] - ca[i];
    }
    for (int i = N - 2; i >= 0; i--) {
      cb[i] += cb[i + 1];
      b[i] += b[i + 1] - cb[i];
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1) printf(" ");
      printf("%lld", a[i] + b[i]);
    }
    printf("\n");
  }

  return 0;
}
