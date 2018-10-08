/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Luqman Arifin
 * Problem : C - Hierarchical Structure
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N];
int age[N];
vector<int> edge[N];

int rmq[2 * N][20], lef[N], rig[N], h[N], cntr;
long long ans[N];

long long bit[N];
vector<int> ages;

void add(int i, long long val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

long long find(int i) {
  long long ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

// at - multiplier - ID ans
vector<tuple<int, int, int>> queries[N];

void dfs(int now) {
  rmq[cntr][0] = now;
  lef[now] = rig[now] = cntr++;
  for (auto it : edge[now]) {
    h[it] = h[now] + 1;
    dfs(it);
    rmq[cntr][0] = now;
    rig[now] = cntr++;
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

void solve(int now) {
  int at_now = lower_bound(ages.begin(), ages.end(), age[now]) - ages.begin();
  add(at_now, age[now]);
  for (auto it : queries[now]) {
    int at, mul, id;
    tie(at, mul, id) = it;
    ans[id] += mul * find(at);
    // printf("tambah %lld pada %d\n", mul * find(at), id);
  }
  for (auto it : edge[now]) solve(it);
  add(at_now, -age[now]);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  for (int i = 1; i <= n; i++) {
    scanf("%d", age + i);
    ages.push_back(age[i]);
  }
  sort(ages.begin(), ages.end());
  ages.resize(distance(ages.begin(), unique(ages.begin(), ages.end())));
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    par[y] = x;
    edge[x].push_back(y);
  }
  int root = 0;
  for (int i = 1; i <= n; i++) if (par[i] == 0) root = i;
  dfs(root);

  for (int j = 1; (1 << j) <= cntr; j++) {
    for (int i = 0; i + (1 << j) <= cntr; i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     printf("%d %d: %d\n", i, j, lca(i, j));
  //   }
  // }

  for (int i = 0; i < q; i++) {
    int a, b, l, r;
    scanf("%d %d %d %d", &a, &b, &l, &r);
    int anc = lca(a, b);
    // printf("%d %d: anc %d\n", a, b, anc);
    if (l <= age[anc] && age[anc] <= r) {
      ans[i] -= age[anc];
    }
    int upp = upper_bound(ages.begin(), ages.end(), r) - ages.begin() - 1;
    int low = lower_bound(ages.begin(), ages.end(), l) - ages.begin() - 1;
    queries[a].emplace_back(upp, +1, i);
    queries[a].emplace_back(low, -1, i);
    queries[b].emplace_back(upp, +1, i);
    queries[b].emplace_back(low, -1, i);
    queries[par[anc]].emplace_back(upp, -2, i);
    queries[par[anc]].emplace_back(low, +2, i);
  }
  solve(root);
  for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
  return 0;
}
