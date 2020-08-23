/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Farras Mohammad Hibban Faddila
 * Problem : C - Mewarnai Papan
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using matrix = vector<vector<ll>>;

const ll MOD = 1e9 + 7;

ll T;
matrix magic;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = ret * a % MOD;}
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

matrix mul(matrix a, matrix b){
  int sz = (int)a.size();
  matrix d(sz, vector<ll>(sz));
  for(int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) {
      for(int k = 0; k < sz; k++) {
        d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return d;
}
 
matrix fastexpo(matrix a, ll b){
  int sz = (int) a.size();
  matrix ret(sz, vector<ll>(sz));
  for(int i = 0; i < sz; i++) ret[i][i] = 1;
  while(b) {
    if(b & 1) ret = mul(ret, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}

ll f(ll n) {
  vector<ll> temp = {2, 8, 24};
  if(n <= 3) return temp[n - 1];
  matrix pw = fastexpo(magic, n - 3);
  ll ret = 0;
  for(int i = 0; i < 3; i++) {
    ret = (ret + pw[0][i] * temp[2 - i]) % MOD;
  }
  return ret;
}

ll f(ll l, ll r) {
  ll ret = f(r + 1) - f(l);
  ret %= MOD;
  ret = (ret * T) % MOD;
  if(ret < 0) ret += MOD;
  return ret;
}

void solve() {
  ll l, r;
  cin >> l >> r;
  ll ans = f(l, r);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  T = inv(2);
  magic = {{3, 0, -2}, {1, 0, 0}, {0, 1, 0}};
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}