/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Wiwit Rifa'i
 * Problem : J - Unicyclic Count
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 17, mod = 1e9 + 7;

int cyc[1 << N][N];

int dp[1 << N], to[N];

int g[N][N];
vector<int> h[N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int determinant(int n, int mat[N][N]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      mat[i][j] %= mod;
      if (mat[i][j] < 0) mat[i][j] += mod;
    }
  }
  int d = 1;
  for (int i = 0; i < n; ++i) {
    int r = i;
    for (int j = i; j < n; ++j) {
      if (mat[j][i] > mat[r][i])
        r = j;
    }
    if (i != r) {
      for (int j = 0; j < n; ++j)
        swap(mat[i][j], mat[r][j]);
      d = -d;
    }
    if (mat[i][i] == 0)
      return 0;
    int mul = powmod(mat[i][i], mod - 2);
    for (int j = i+1; j < n; ++j) {
      int now = 1LL * mul * mat[j][i] % mod;
      for (int k = 0; k < n; ++k) {
        mat[j][k] = (mat[j][k] - 1LL * mat[i][k] * now) % mod;
        if (mat[j][k] < 0) mat[j][k] += mod;
      }
    }
  }
  for (int i = 0; i < n; ++i)
    d = (1LL * d * mat[i][i]) % mod;
  if (d < 0) d += mod;
  return d;
}

int kir[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u][v] = 1;
    g[v][u] = 1;
    h[u].push_back(v);
    h[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    cyc[1 << i][i] = 1;
  }
  int nmask = 1 << n;
  for (int mask = 0; mask < nmask; ++mask) {
    for (int j = 0; j < n; ++j) {
      if ((mask & (1 << j)) == 0) continue;
      if (cyc[mask][j] == 0) continue;
      for (int i = 0; (1 << i) <= mask; ++i) {
        if (mask & (1 << i)) continue;
        if (!g[i][j]) continue;
        add(cyc[mask|(1<<i)][i], cyc[mask][j]);
      }
    }
  }

  for (int mask = 0; mask < nmask; ++mask) {
    if (__builtin_popcount(mask) <= 2) continue;
    int k = 0;
    while ((1 << (k+1)) <= mask) ++k;
    for (int i = 0; i < k; ++i) {
      if (!(mask & (1 << i))) continue;
      if (!g[i][k]) continue;
      add(dp[mask], cyc[mask][i]);
    }
  }
  int inv2 = (mod + 1) / 2;
  int ans = 0;
  for (int mask = 0; mask < nmask; ++mask) {
    dp[mask] = (1LL * dp[mask] * inv2) % mod;
    if (dp[mask] == 0) continue;
    int id = 1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1<< i))
        to[i] = 0;
      else
        to[i] = id++;
    }
    memset(kir, 0, sizeof kir);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((mask & (1 << i)) && (mask & (1 << j))) continue;
        if (g[i][j] == 0) continue;
        --kir[to[i]][to[j]];
      }
    }
    for (int i = 0; i < id; ++i) {
      int sum = 0;
      for (int j = 0; j < id; ++j)
        sum -= kir[i][j];
      kir[i][i] = sum;
    }
    ans = (ans + 1LL * determinant(id-1, kir) * dp[mask]) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%d\n", ans);
  return 0;
}
