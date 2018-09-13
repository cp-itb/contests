#include <bits/stdc++.h>

using namespace std;


const int N = 4;
const long long mod = 1e9 + 7;
struct matrix {
  int n, m;
  long long _mat[N][N];
  matrix(int n, int m) : n(n), m(m) {
  }
  void reset() {
    memset(_mat, 0, sizeof _mat);
    for(int i = 0; i<n; i++)
      _mat[i][i] = 1;
  }
  const long long * operator[](const int id) const {
    return _mat[id];
  }
  long long * operator[](const int id) {
    return _mat[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<this->n; i++) {
      for(int j = 0; j<mat.m; j++) {
        long long &now = ret[i][j];
        now = 0;
        for(int k = 0; k<this->m; k++) {
          now = (now + this->_mat[i][k] * mat[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  void print() {
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<m; j++)
        cout << _mat[i][j] << " ";
      cout << endl;
    }
  }
  matrix operator^(long long pw) const {
    matrix ret(n, m), base = *this;
    ret.reset();
    while(pw) {
      if(pw & 1)
        ret = ret*base;
      base = base*base;
      pw >>= 1;
    }
    return ret;
  }
};


int main() {
  long long n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  matrix dp(2, 2);
  dp[0][0] = n-2;
  dp[0][1] = n-1;
  dp[1][0] = 1;
  dp[1][1] = 0;
  matrix sama(2, 1), beda(2, 1), semua(2, 1);
  sama[0][0] = 0;
  sama[1][0] = 1;
  beda[0][0] = 1;
  beda[1][0] = 0;
  semua[0][0] = n-1;
  semua[1][0] = 1;
  long long ans = 1, last = 1, lastb = 0;
  for (int i = 0; i < k; i++) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (i == 0) {
      if (a > 1) {
        matrix now = (dp ^ (a-last)) * semua;
        ans = (ans * now[1][0]) % mod;
      }
    }
    else {
      matrix now(2, 1);
      if (b == lastb)
        now = (dp ^ (a - last)) * sama;
      else
        now = (dp ^ (a - last)) * beda;
      ans = (ans * now[1][0]) % mod;
    }
    last = a;
    lastb = b;
  }
  if (last < m) {
    matrix now = (dp ^ (m-last)) * semua;
    ans = (ans * now[1][0]) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}