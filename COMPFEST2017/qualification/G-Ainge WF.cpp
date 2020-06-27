/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : G
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long ret = 1;
  for (; p; p >>= 1, b = (b * b) % mod)
    if (p & 1) ret = (ret * b) % mod;
  return ret;
}

int fp[N];
long long cnt[N];
long long fac[N], inv[N];
long long C(long long n, long long k) {
  assert(!(n < k || k < 0));
  return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}

int main() {
  for (int i = 0; i < N; i++)
    fp[i] = 0;
  fp[1] = 1;
  for (int i = 2; i < N; i++) if (fp[i] == 0) {
    for (int j = i; j < N; j += i)
      if (fp[j] == 0)
        fp[j] = i;
  }
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (1LL * fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod - 2);
    assert((fac[i] * inv[i] % mod) == 1);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < N; i++)
      cnt[i] = 0;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      while (a > 1) {
        int p = fp[a];
        assert(fp[p] == p);
        while ((a % p) == 0) {
          a /= p;
          cnt[p]++;
        }
      }
    }
    long long ans = 1;
    for (int i = 2; i < N; i++) {
      ans = (ans * C(cnt[i] + n-1, n-1)) % mod;
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    assert(ans >= 0 && ans < mod);
    cout << ans << endl;
  }

  return 0;
}
