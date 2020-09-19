/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Farras Hibban
 * Problem  : F
 */

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int M = 2e5;

ll fc[M + 5], ifc[M + 5];

ll fast_expo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = (ret * a) % MOD; }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

void init_fac() {
  fc[0] = 1;
  for(ll i = 1; i <= M; i++) { fc[i] = (fc[i - 1] * i) % MOD; }
  ifc[M] = fast_expo(fc[M], MOD - 2);
  for(ll i = M - 1; i >= 0; i--) { ifc[i] = ifc[i + 1] * (i + 1) % MOD; }
}

ll C(ll a, ll b) {
  if(a < 0 || b < 0 || a < b) { return 0; }
  ll ret = fc[a];
  ret = (ret * ifc[b]) % MOD;
  ret = (ret * ifc[a - b]) % MOD;
  return ret;
}

void solve() {
  init_fac();

  ll n;
  cin >> n;

  ll x, sum = 0, m = 0;
  while(cin >> x) { sum += x, m++; }

  ll ans = C(n - sum + m - 1, m - 1);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}