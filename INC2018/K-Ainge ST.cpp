/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Wiwit Rifa'i
 * Problem : K - Living Subgraph
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 4;

vector<int> g[N];
int d[N], p[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
  }
  int best = n+1;
  for (int s = n-1; s >= 0; --s) {
    queue<int> que;
    que.push(s);
    fill(d, d+n+1, -1);
    fill(p, p+n+1, -1);
    d[s] = 0;
    while (!que.empty()) {
      int v = que.front(); que.pop();
      bool done = 0;
      for (int u : g[v]) {
        if (p[v] == u) continue;
        if (d[u] != -1) {
          int cur = d[u] + d[v] + 1;
          best = min(cur, best);
          if (d[u] != d[v]) {
            continue;
          }
          done = 1;
          break;
        }
        d[u] = d[v] + 1;
        p[u] = v;
        if (d[u] + d[u] + 1 < best)
          que.push(u);
      }
      if (done)
        break;
    }
    for (int u : g[s]) {
      assert(g[u].back() == s);
      g[u].pop_back();
    }
  }
  if (best > n)
    best = -1;
  printf("%d\n", best);
  return 0;
}
