 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : DryCr1TiKaL
  * Author  : Michel Fang + Morgen Sudyanto
  * Problem : J - Maximum Sum of Array
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
  ll ar[n], pre[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    pre[i] = max(ar[i], 0ll);
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      pre[i] = max({pre[i - 1], ar[i], 0ll});
    }
  }
  ll curmax = 0;
  for (int i = m; i < n; i++) {
    pre[i] = max({pre[i - m] + ar[i], ar[i], 0ll, pre[i - m], curmax + ar[i]});
    curmax = max(curmax, pre[i-m]);
  }
  ll ans = -1e9;
  for (int i = 0; i < n; i++) {
    ans = max(ans, ar[i]);
  }
  if (ans < 0) {
      cout << ans << endl;
      return 0;
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, pre[i]);
    // cerr << pre[i] << ' ';
  }
  cout << ans << '\n';
  return 0;
}
/*
5 4
-1 -2 -3 -4 -5

5 4
2 7 -5 1 4

6 3
2 5 -3 1 7 9

10 2
-1 2 5 7 -1 2 3 -2 4 8
20
*/