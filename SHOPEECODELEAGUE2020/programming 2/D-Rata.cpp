/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Rata
* Author  : Wiwit Rifai
* Problem : D - Number Tree
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> g[N];

int sz[N], biggest[N], live[N];

void get_size(int v, int par) {
  sz[v] = 1;
  biggest[v] = -1;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par || !live[u]) continue;
    get_size(u, v);
    sz[v] += sz[u];
    if (biggest[v] == -1 || sz[u] > sz[biggest[v]])
      biggest[v] = u;
  }
}

const int mod = 1e9 + 7;

int bit_down[N], bit_up[N];

void upd_down(int x, int v) {
  for (++x; x < N; x += x&-x) {
    bit_down[x] += v;
    if (bit_down[x] >= mod)
      bit_down[x] -= mod;
  }
}

int get_down(int x) {
  int ret = 0;
  for (++x; x; x -= x&-x) {
    ret += bit_down[x];
    if (ret >= mod)
      ret -= mod;
  }
  return ret;
}

void upd_up(int x, int v) {
  for (++x; x; x -= x&-x) {
    bit_up[x] += v;
    if (bit_up[x] >= mod)
      bit_up[x] -= mod;
  }
}

int get_up(int x) {
  int ret = 0;
  for (++x; x < N; x += x&-x) {
    ret += bit_up[x];
    if (ret >= mod)
      ret -= mod;
  }
  return ret;
}

void dfs_upd(int v, int par, int mul_up, int mul_down, long long ten, bool rev = false) {
  upd_up(v, mul_up);
  upd_down(v, mul_down);
  ten = (ten * 10LL) % mod;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par || !live[u]) continue;
    int mul_up2 = (mul_up * 10LL + (rev ? mod-e.second : e.second)) % mod;
    int mul_down2 = (mul_down + e.second * ten) % mod;
    dfs_upd(u, v, mul_up2, mul_down2, ten, rev);
  }
}

long long dfs_get(int v, int par, long long ten) {
  long long ret = (get_up(v) + get_down(v) * ten) % mod;
  ten = (ten * 10LL) % mod;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par || !live[u]) continue;
    ret += dfs_get(u, v, ten);
    if (ret >= mod)
      ret -= mod;
  }
  return ret;
}

long long centroid(int v) {
  get_size(v, v);
  int tot = sz[v];
  while (biggest[v] != -1 && sz[biggest[v]] * 2 >= tot)
    v = biggest[v];
  long long ans = 0;
  for (auto & e : g[v]) {
    int u = e.first;
    if (!live[u]) continue;
    ans += dfs_get(u, v, 10);
    if (ans >= mod)
      ans -= mod;
    dfs_upd(u, v, e.second, e.second, 1);
  }

  ans = (ans + get_down(v) + get_up(v)) % mod;

  for (auto & e : g[v]) {
    int u = e.first;
    if (!live[u]) continue;
    int rev = mod - e.second;
    if (rev >= mod)
      rev -= mod;
    dfs_upd(u, v, rev, rev, mod - 1, true);
  }

  reverse(g[v].begin(), g[v].end());

  for (auto & e : g[v]) {
    int u = e.first;
    if (!live[u]) continue;
    ans += dfs_get(u, v, 10);
    if (ans >= mod)
      ans -= mod;
    dfs_upd(u, v, e.second, e.second, 1);
  }


  for (auto & e : g[v]) {
    int u = e.first;
    if (!live[u]) continue;
    int rev = mod - e.second;
    if (rev >= mod)
      rev -= mod;
    dfs_upd(u, v, rev, rev, mod - 1, true);
  }

  live[v] = false;

  for (auto & e : g[v]) {
    int u = e.first;
    if (!live[u]) continue;
    ans = (ans + centroid(u)) % mod;
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    --u, --v;
    g[u].emplace_back(v, c);
    g[v].emplace_back(u, c);
  }
  fill(live, live+n, true);
  printf("%lld\n", centroid(0));
  return 0;
}