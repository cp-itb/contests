/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : D - Xor-or
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;

vector<pair<int, int>> edge[N];
int c[N];
long long cnt[2];

int dfs(int now, int bef, int col, int i) {
  if (c[now] != -1) {
    return c[now] == col;
  }
  c[now] = col;
  cnt[col]++;
  bool good = 1;
  for (auto it : edge[now]) {
    int near = it.first;
    int w = it.second;
    if (near == bef) continue;
    if (w & (1 << i)) {
      if (dfs(near, now, col ^ 1, i) == 0) {
        good = 0;
      }
    } else {
      if (dfs(near, now, col, i) == 0) {
        good = 0;
      }
    }
  }
  return good;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      edge[u].emplace_back(v, w);
      edge[v].emplace_back(u, w);
    }
    long long ans = 0;
    for (int j = 0; j < 31; j++) {
      memset(c, -1, sizeof(c));
      for (int i = 1; i <= n; i++) {
        if (c[i] == -1) {
          cnt[0] = cnt[1] = 0;
          // ada negative cycle
          if (dfs(i, 0, 0, j) == 0) {
            long long all = cnt[0] + cnt[1];
            //printf("all %d\n", (1 << j));
            ans += all * (all - 1) / 2 * (1LL << j);
          } else {
            //printf("%d %lld %lld\n", (1 << j), cnt[0], cnt[1]);
            ans += cnt[0] * cnt[1] * (1LL << j);
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
