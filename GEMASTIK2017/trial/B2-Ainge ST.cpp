/**
 * Contest : GEMASTIK 2017 Pemanasan
 * Team    : Ainge ST
 * Author  : Wiwit Rifa'i
 * Problem : B2 - Menggemaskan dan Cantik (Sulit)
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int can[12], k;
int id[N], a[3], x[3], ca[3], cx[3];
long long g[N], cc[N];
long long best;
char s[N][10];

void dfs(int i, int ng, int nc, long long vg, long long vc) {
  if (i == k) {
    if (ng == 3 && nc == 3) {
      if (best < vg + vc) {
        best = vg + vc;
        for (int i = 0; i < 3; i++)
          x[i] = cx[i], a[i] = ca[i];
      }
    }
    return;
  }

  if (ng < 3) {
    ca[ng] = can[i];
    dfs(i+1, ng+1, nc, vg * g[can[i]], vc);
  }
  if (nc < 3) {
    cx[nc] = can[i];
    dfs(i+1, ng, nc+1, vg, vc * cc[can[i]]);
  }
  dfs(i+1, ng, nc, vg, vc);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s %d %d", s[i], g+i, cc+i);
      id[i] = i;
    }
    sort(id, id+n, [](int le, int ri) { return g[le] > g[ri]; });
    k = 0;
    for (int i = 0; i < min(n, 6); i++)
      can[k++] = id[i];
    sort(id, id+n, [](int le, int ri) { return cc[le] > cc[ri]; });
    for (int i = 0; i < min(n, 6); i++)
      can[k++] = id[i];
    sort(can, can+k);
    best = 0;
    k = unique(can, can+k) - can;
    dfs(0, 0, 0, 1, 1);
    printf("%lld\n", best);
    for (int i = 0; i < 3; i++)
      printf("%s%c", s[a[i]], i == 2 ? '\n' : ' ');
    for (int i = 0; i < 3; i++)
      printf("%s%c", s[x[i]], i == 2 ? '\n' : ' ');
  }
  return 0;
}
