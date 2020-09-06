/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Farras M. H. Faddila
 * Problem : B - Bintang Ojol
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, m;

void solve() {
  cin >> n >> m;
  if((5 * m < n) || (m > n)) {
    cout << -1 << ' ' << -1 << '\n';
    return;
  }
  ll mn = max(0LL, (n - 4 * m));
  ll mx = (n - m) / 4;
  cout << mn << ' ' << mx << '\n';
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