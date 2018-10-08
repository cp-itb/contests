/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Wiwit Rifa'i
 * Problem : I - Expected Value of a Permutation
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N], p[N];
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; j += i)
      ++cnt[j];
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = fac[i-1] * i % mod;
  inv[n] = powmod(fac[n], mod - 2);
  for (int i = n-1; i >= 0; --i)
    inv[i] = inv[i+1] * (i+1) % mod;
  vector<int> vk;
  for (int i = 1; i <= n; ++i) {
    vk.push_back(cnt[i]);
  }
  sort(vk.begin(), vk.end());
  vk.erase(unique(vk.begin(), vk.end()), vk.end());
  for (int k : vk) {
    p[k] = 0;
    long long now = 1LL * fac[n-k] * k % mod;
    for (int j = 1; j <= n-k; ++j) {
      long long cur = 1LL * now * inv[n-k-j] % mod;
      cur = cur * fac[n-j-1] % mod;
      cur = cur * (j) % mod;
      p[k] = (p[k] + cur) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    ans = (ans + 1LL * a * p[cnt[i]]) % mod;
  }
  ans = 1LL * ans * inv[n] % mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}
