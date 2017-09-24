/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : G - Petruk's Sequence
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 4, mod = 1e9 + 7;

struct matrix {
  int a[4][4];
  matrix() {
    memset(a, 0, sizeof a);
  }
  int* operator[](int id) {
    return a[id];
  }
  matrix operator*(matrix& other) {
    matrix res;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        long long now = 0;
        for (int k = 0; k < 3; k++) {
          now = (now + 1LL * a[i][k] * other[k][j]) % mod; 
        }
        res[i][j] = now;
      }
    }
    return res;
  }
  matrix operator^(long long pw) {
    matrix ret;
    for (int i = 0; i < 3; i++)
      ret[i][i] = 1;
    matrix cur = *this;
    for (; pw; pw >>= 1, cur = cur * cur) {
      if (pw & 1) ret = ret * cur;
    } 
    return ret;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int a, b, c, d, k;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    int ans = 0;
    if (k == 0)
      ans = c % mod;
    else if (k == 1)
      ans = (c + d) % mod;
    else {
      matrix m;
      m[0][0] = m[0][1] = 1;
      m[1][1] = a;
      m[1][2] = b;
      m[2][1] = 1;
      matrix f;
      f[0][0] = c;
      f[1][0] = d;
      f[2][0] = c;
      matrix res = (m ^ k) * f;
      ans = res[0][0];
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("Case #%d: %d\n", tc, ans);
  }

  return 0;
}
