/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Farras Faddila
 * Problem  : I
 */
/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
/** END OF DESPERATE OPTIMIZATION **/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map<ll, ll> mp;
map<ll, ll> mp2;

ll getVar(ll x, ll y) {
  ll fpb = __gcd(x, y);
  ll dx = x / fpb;
  ll dy = y / fpb;
  ll banyak = max((((ll)1e12) / fpb) - dx * dy, 0LL);
  banyak += (dx - 1) * (dy - 1) / 2;
  return banyak;
}

void solve() {
  int n, q;
  cin >> n >> q;
  const int MX = n * (n - 1) / 2;

  vector<ll> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];

  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll variety = getVar(w[i], w[j]);
      mp[variety]++;
      // cerr << variety << '\n';
    }
  }

  for (auto i : mp) {
    mp2[i.second]++;
  }
  vector<int> ve, cnt;
  ve.emplace_back(0);
  cnt.emplace_back(0);
  for (auto i : mp2) {
    ve.emplace_back(i.first);
    cnt.emplace_back(i.second);
  }

  int unq = (int)ve.size();
  vector<vector<int>> dp(unq + 1, vector<int>(MX + 1, -1));
  for (int i = 0; i <= unq; i++) {
    dp[i][0] = 0;
  }

  for (int i = 1; i <= unq; i++) {
    for (int j = 1; j <= MX; j++) {
      if (dp[i - 1][j] >= 0) {
        dp[i][j] = 0;
      } else if (j >= ve[i] && dp[i][j - ve[i]] >= 0 && dp[i][j - ve[i]] < cnt[i]) {
        dp[i][j] = dp[i][j - ve[i]] + 1;
      } else {
        dp[i][j] = -1;
      }
    }
  }

  // cerr << "unq " << unq << '\n';
  // for (int i = 0; i < unq; i++) {
  //   cerr << ve[i] << ' ' << cnt[i] << '\n';
  // }

  while (q--) {
    ll k;
    cin >> k;
    // cerr << k << '\n';
    // cerr << k << ' ' << dp[unq][k] << '\n';
    bool ans = (dp[unq][k] != -1);
    cout << (ans ? "YES" : "NO") << '\n';
  } 
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