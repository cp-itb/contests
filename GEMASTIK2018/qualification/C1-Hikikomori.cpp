/**
 * Contest : GEMASTIK 2018 Qualification
 * Team    : Hikikomori
 * Author  : Wiwit Rifa'i
 * Problem : C1
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long f[N], fac[N], inv[N];

inline long long mul(long long x, long long y) {
  return x * y % mod;
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = mul(b, b))
    if (p & 1)
      r = mul(r, b);
  return r;
}

inline long long C(int n, int k) {
  if (n < k || k < 0 || n < 0)
    return 0;
  return mul(fac[n], mul(inv[n-k], inv[k]));
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = mul(fac[i-1], i);
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i >= 0; --i)
    inv[i] = mul(inv[i+1], i+1);
  f[0] = 1;
  f[1] = 0;
  for (int i = 2; i < N; ++i) {
    f[i] = mul(f[i-2], mul(C(i-1,1), C(i,2))) + mul(f[i-1], mul(C(i-1,1), C(i,1)));
    if (f[i] >= mod)
      f[i] -= mod;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
      ans += mul(f[n-i], mul(C(n, i), mul(C(n, i), fac[i])));
      if (ans >= mod)
        ans -= mod;
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
