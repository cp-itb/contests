/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Rata
* Author  : Wiwit Rifai
* Problem : B - Shopee Logistics
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], c[N], pe[N];
long long depth[N];
long long down[N], up[N];
bool used[N];

vector<int> g[N];

void find_diameter(int v, int par) {
  pe[v] = par;
  if (par < 0)
    depth[v] = 0;
  for (int e : g[v]) {
    if (e == par) continue;
    int u = a[e] ^ v;
    depth[u] = depth[v] + c[e];
    find_diameter(u, e);
  }
}

void dfs1(int v, int par) {
  down[v] = 0;
  for (int e : g[v]) {
    if (e == par) continue;
    int u = a[e] ^ v;
    dfs1(u, e);
    down[v] = max(down[v], c[e] + down[u]);
  }
}

long long dfs2(int v, int par) {
  long long cur = 0;
  for (int e : g[v]) {
    if (e == par) continue;
    int u = a[e] ^ v;
    up[u] = max(up[u], cur + c[e]);
    cur = max(cur, down[u] + c[e]);
  }
  reverse(g[v].begin(), g[v].end());
  cur = up[v];
  long long ans = 0;
  for (int e : g[v]) {
    if (e == par) continue;
    int u = a[e] ^ v;
    up[u] = max(up[u], cur + c[e]);
    cur = max(cur, down[u] + c[e]);
    if (!used[e]) {
      ans = max(ans, up[u] + down[u]);
    }
  }

  for (int e : g[v]) {
    if (e == par) continue;
    int u = a[e] ^ v;
    ans = max(ans, dfs2(u, e));
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d %d %d", a+i, b+i, c+i);
    --a[i], --b[i];
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
    a[i] ^= b[i];
  }
  find_diameter(0, -1);
  int l = max_element(depth, depth+n) - depth;
  find_diameter(l, -1);
  int r = max_element(depth, depth+n) - depth;
  long long ans = depth[r] - c[pe[r]];
  int v = r;
  while (pe[v] != -1) {
    int u = a[pe[v]] ^ v;
    used[pe[v]] = true;
    if (u == l)
      ans = max(ans, depth[r] - c[pe[v]]);
    v = u;
  }
  dfs1(0, -1);
  ans = max(ans, dfs2(0, -1));
  printf("%lld\n", ans);
  return 0;
}