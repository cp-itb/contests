/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : F
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 6020, mod = 1e9 + 7;

vector< pair<int, int > > g[N];
bool vis[N][N];
bool zero[N];
long long fac[N];

void dfs(int v) {
  zero[v] = 1;
  for (auto it : g[v]) if (it.second == 0 && !zero[it.first])
    dfs(it.first);
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (1LL * fac[i-1] * i) % mod;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
      g[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    memset(vis, 0, sizeof vis);
    vis[0][0] = 1;
    queue<pair<int, int > > que;
    que.push(make_pair(0, 0));
    while (!que.empty()) {
      int v = que.front().first, k = que.front().second;
      if (k + 1 >= N) break;
      que.pop();
      for (auto it : g[v]) if (it.second <= k) {
        int u = it.first;
        if (vis[u][k+1]) continue;
        vis[u][k+1] = 1;
        que.push(make_pair(u, k+1));
      }
    }
    int k = -1;
    memset(zero, 0, sizeof zero);
    dfs(n-1);
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < n; j++) if (zero[j])
      if (vis[j][i]) {
        k = i;
        break;
      }
      if (k >= 0)
        break;

    }
    if (k < 0) {
      puts("-1");
    }
    else {
      vector< int > cur;
      for (int i = 0; i < n; i++) if (zero[i] && vis[i][k])
        cur.push_back(i);
      long long ans = 0;
      for (int i = k; i > 0; i--) {
        int mi = k;
        for (int v : cur) {
          for (auto it : g[v]) if (vis[it.first][i-1] && it.second < i) {
            mi = min(mi, it.second);
          }
        }
        vector<int> next;
        next.clear();
        for (int v : cur) {
          for (auto it : g[v]) if (vis[it.first][i-1] && it.second == mi) {
            next.push_back(it.first);
          }
        }
        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());
        cur = next;
        assert(mi < i);
        ans = (ans + 1LL * fac[i] * mi) % mod;
      }
      ans %= mod;
      if (ans < 0) ans += mod;
      assert(cur.size() == 1 && cur[0] == 0);
      printf("%lld\n", ans);
    }
  }

  return 0;
}
