/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Wiwit Rifa'i
 * Problem : I - Classical Counting
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 7, N = 3 * mod + 1;

int cnt[N][2], wo[N];
int fp[2] = {29, 34483};
long long pw[2][N];
long long fac[N], inv[N];

long long C(long long n, long long k) {
  assert(n < N);
  if (n < k || n < 0 || k < 0) return 0;
  long long ret = ((1LL * fac[n] * inv[k] % mod) * inv[n-k]) % mod;
  for (int i = 0; i < 2; ++i) {
    int sisa = cnt[n][i] - cnt[k][i] - cnt[n-k][i];
    assert(sisa >= 0 && sisa < N);
    ret = (ret * pw[i][sisa]) % mod;
  }
  return ret;
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long H(long long n, long long k) {
  return C(n+k-1, k-1);
}

int main() {
  assert(fp[0] * fp[1] == mod);
  memset(cnt, 0, sizeof cnt);
  wo[0] = 1;
  fac[0] = inv[0] = 1;
  int euler = (fp[0] - 1) * (fp[1] - 1);
  for (int i = 1; i < N; ++i) {
    wo[i] = i;
    for (int j = 0; j < 2; ++j) {
      cnt[i][j] = cnt[i-1][j];
      int p = fp[j];
      while ((wo[i] % p) == 0) {
        wo[i] /= p;
        ++cnt[i][j];
      }
    }
    fac[i] = 1LL * wo[i] * fac[i-1] % mod;
    inv[i] = powmod(fac[i], euler-1);
    assert((inv[i] * fac[i] % mod) == 1);
  }
  for (int i = 0; i < 2; ++i) {
    pw[i][0] = 1;
    for (int j = 1; j < N; ++j)
      pw[i][j] = 1LL * pw[i][j-1] * fp[i] % mod;
  }
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  long long all = k;
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (all < 0) break;
    long long now = H(all, n) * C(n, i) % mod;
    if (i & 1)
      now = mod - now;
    ans = (ans + now) % mod;
    all -= m+1;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}
