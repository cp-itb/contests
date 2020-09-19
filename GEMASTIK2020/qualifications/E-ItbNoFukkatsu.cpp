/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Farras Hibban
 * Problem  : E
 */

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
const ll MOD = 1e8 + 37;

ll a[N + 5];

ll fast_expo(ll a, ll b, ll mod) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = (ret * a) % mod; }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ret;
}

ll getphi(ll x) {
  ll tmp = 1;
  for(ll i = 2; i * i <= x; i++) {
    if(x % i == 0) {
      tmp *= (i - 1);
      x /= i;
      while(x % i == 0) { x /= i, tmp *= i; }
    }
  }
  if(x != 1) { tmp *= (x - 1); }
  return tmp;
}

ll get(ll idx, ll mod) {
  if(idx == 1) { return (a[idx] % mod); }
  if(mod == 1) { return 0; }
  ll pw = get(idx - 1, getphi(mod));
  return fast_expo(a[idx], pw, mod);
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) { cin >> a[n + 1 - i]; }
  cout << get(n, MOD) << '\n';
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