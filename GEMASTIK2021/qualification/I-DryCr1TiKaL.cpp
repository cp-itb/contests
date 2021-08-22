 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : DryCr1TiKaL
  * Author  : Michel Fang
  * Problem : I - Plagiarisme
  */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  ll s[n][m], t[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
    }
  }
  vector<ll> mxsoal(m, -1e18);
  for (int j = 0; j < m; j++) {
    vector<ll> mxcs(8, -1e18), mncs(8, 1e18);
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < 8; mask++) {
        ll val = 0;
        if ((mask & 1) == 0) {
          val += i;
        } else {
          val -= i;
        }
        if (((mask >> 1) & 1) == 0) {
          val += s[i][j];
        } else {
          val -= s[i][j];
        }
        if (((mask >> 2) & 1) == 0) {
          val += t[i][j];
        } else {
          val -= t[i][j];
        }
        mxcs[mask] = max(mxcs[mask], val);
        mncs[mask] = min(mncs[mask], val);
      }
    }
    for (int mask = 0; mask < 8; mask++) {
      mxsoal[j] = max(mxsoal[j], mxcs[mask] - mncs[mask]);
    }
  }
  ll ans = -1e18;
  for (int i = 0; i < m; i++) {
    ans = max(ans, mxsoal[i]);
  }
  cout << ans << '\n';
  return 0;
}