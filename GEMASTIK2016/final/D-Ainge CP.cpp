/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : D
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

long long lef[N], rig[N];
long long cl[N], cr[N];

long long tot[N];


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(lef, 0, sizeof(lef));
    memset(rig, 0, sizeof(rig));
    memset(cl, 0, sizeof(cl));
    memset(cr, 0, sizeof(cr));
    memset(tot, 0, sizeof(tot));

    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
      long long x, k;
      scanf("%lld %lld", &x, &k);
      if (x -1 >= 0) lef[x - 1] += k - 1;
      rig[x] += k;
       
      cr[x]++;
      if (x + k < N) cr[x + k]--;

      if (x - 1 >= 0) cl[x - 1]++;
      if (x - k >= 0) cl[x - k]--;
    }
    long long now = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
      cnt += cr[i];
      now += rig[i];

      tot[i] += now;

      now -= cnt;
    }

    now = 0; cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
      cnt += cl[i];
      now += lef[i];

      tot[i] += now;

      now -= cnt;
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1) printf(" ");
      printf("%lld", tot[i]);
    }
    printf("\n");
  }

  return 0;
}
