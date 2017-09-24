/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : E
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, k;
vector<int> edge[N];
int dp[N];
bool ok[N];

void dfs(int now, int bef, int t) {
  bool leaf = 1;
  int maxi = -N;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now, t);
    leaf = 0;
    maxi = max(maxi, dp[it]);
  }
  if (leaf) {
    dp[now] = 0;
  } else {
    dp[now] = maxi + 1;
  }
  if (dp[now] == t) {
    ok[now] = 1;
    dp[now] = -t - 1;
  }
}

bool can(int t) {
  memset(ok, 0, sizeof(ok));
  dfs(1, -1, t);
  int need = 0;
  for (int i = 1; i <= n; i++) need += ok[i];
  return need <= k;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) edge[i].clear();
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", l);
  }

  return 0;
}
