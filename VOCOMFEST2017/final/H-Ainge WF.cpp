/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : H - Amazing String
 */

#include <bits/stdc++.h>

using namespace std;

const long long PRIME = 89;
const long long mod = 1e9 + 4207;

const int N = 2e5 + 5;

char s[N];
long long hp[N], h[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) tmp = tmp * a % mod;
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

// hash from A with len, dikali m kali
long long arith(long long a, int len, long long m) {
  long long r = hp[len];
  return a * (power(r, m) - 1) % mod * inv(r - 1) % mod;
}

void norm(long long& val) {
  val %= mod;
  if (val < 0) val += mod;
}

long long got(int l, int r) {
  long long ret = h[r] - h[l-1] * hp[r-l+1];
  norm(ret);
  return ret;
}

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  hp[0] = 1;
  for (int i = 1; i < N; i++) hp[i] = hp[i-1] * PRIME % mod;
  for (int i = 1; i <= n; i++) h[i] = (h[i-1] * PRIME + s[i] - 'a' + 1) % mod;

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int a1, b1, c1;
    int a2, b2, c2;
    int d1, e1, f1;
    int d2, e2, f2;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d",
      &a1, &b1, &c1,
      &a2, &b2, &c2,
      &d1, &e1, &f1,
      &d2, &e2, &f2);
    printf("Case #%d: ", tt);
    long long nlef = 1LL * (b1 - a1 + 1) * c1 + 1LL * (b2 - a2 + 1) * c2;
    long long nrig = 1LL * (e1 - d1 + 1) * f1 + 1LL * (e2 - d2 + 1) * f2;
    if (nlef != nrig) {
      puts("NO");
      continue;
    }
    long long lef1 = arith(got(a1, b1), b1-a1+1, c1);
    long long lef2 = arith(got(a2, b2), b2-a2+1, c2);
    long long rig1 = arith(got(d1, e1), e1-d1+1, f1);
    long long rig2 = arith(got(d2, e2), e2-d2+1, f2);
    long long lef = (lef1 * power(PRIME, 1LL*(b2-a2+1)*c2) + lef2) % mod;
    long long rig = (rig1 * power(PRIME, 1LL*(e2-d2+1)*f2) + rig2) % mod;
    puts(lef == rig? "YES" : "NO");
  }
  return 0;
}
