/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : J - Rational Number
 */

#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}
long long powmod(long long b, long long p, long long m) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % m;
    b = (b * b) % m;
    p >>= 1;
  }
  return ret;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    a = abs(a);
    b = abs(b);
    long long d = gcd(a, b);
    a /= d;
    b /= d;
    while ((b % 2) == 0)
      b /= 2;
    while ((b % 5) == 0) 
      b /= 5;
    long long ans = 0;
    if (b > 1) { 
      long long tot = b, now = b;
      for (long long i = 2; i * i <= b; i++) if ((now % i) == 0) {
        tot -= tot/i;
        while ((now % i) == 0) {
          now /= i;
        }
      }
      if (now > 1)
        tot -= tot/now;
      ans = tot;
      for (long long i = 1; i * i <= tot; i++) if ((tot % i) == 0) {
        if (powmod(10, i, b) == 1) {
          ans = min(ans, i);
        }
        long long j = tot/i;
        if (powmod(10, j, b) == 1) {
          ans = min(ans, j);
        }
      }
    }
    printf("Case #%d: %lld\n", tt, ans);
  }
  return 0;
}