/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Farras M. H. Faddila
 * Problem : D - Distribusi Kelompok
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int N = 1e6;

int n;
ll sum = 0;
ll fc[N + 5], ifc[N + 5];
int cnt[N + 5];

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = (ret * a) % MOD; }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

void init_fac() {
  fc[0] = 1;
  for(int i = 1; i <= N; i++) {
    fc[i] = fc[i - 1] * i % MOD;
  }
  ifc[N] = inv(fc[N]);
  for(int i = N - 1; i >= 0; i--) {
    ifc[i] = ifc[i + 1] * (i + 1) % MOD;
  }
}

void solve() {
  init_fac();
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    sum = sum + x;
  }
  ll ans = fc[sum];
  for(int i = 1; i <= N; i++) {
    if(cnt[i] == 0) continue;
    for(int j = 1; j <= cnt[i]; j++) {
      ans = ans * ifc[i] % MOD;
    }
    ans = ans * ifc[cnt[i]] % MOD;
  }
  ans %= MOD;
  if(ans < 0) ans += MOD;
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