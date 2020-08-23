/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Farras Mohammad Hibban Faddila
 * Problem : D - Pembagi Ganjil Terbesar
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = (ret * a) % MOD;}
    a = (a * a) % MOD;
    b >>= 1;
  }
  ret %= MOD;
  if(ret < 0) ret += MOD;
  return ret;
}

ll discrete_log(ll a, ll b, ll m) {
  a %= m, b %= m;
  ll n = sqrtl(m) + 1;

  ll an = 1;
  for (ll i = 0; i < n; ++i)
    an = (an * a) % m;

  unordered_map<ll, ll> vals;
  for (ll q = 0, cur = b; q <= n; ++q) {
    vals[cur] = q;
    cur = (((cur * a) % m) + m) % m;
  }

  for (ll p = 1, cur = 1; p <= n; ++p) {
    cur = (((cur * an) % m) + m) % m;
    if(vals.count(cur)) {
      ll ans = n * p - vals[cur];
      ans %= (m - 1);
      if(ans < 0) ans += (m - 1);
      return ans;
    }
  }
  return -1;
}

void solve() {
  ll x;
  cin >> x;
  ll find = 3LL * x - 2;
  find %= MOD;
  if(find < 0) find += MOD;
  ll ans = discrete_log(4, find, MOD);
  if(ans == -1) cout << -1 << '\n';
  else {
    ans %= (MOD - 1);
    if(ans < 0) ans += (MOD - 1);
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}