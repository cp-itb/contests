/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Farras Faddila
 * Problem  : E
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void build(int n) {
  int oc[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      oc[i][j] = 0;
    }
  }
  pair<int, int> pos_awal = make_pair(0, n - 1);
  for (int t = 0; t < n; t++) {
    int x = pos_awal.first;
    int y = pos_awal.second;
    oc[x][y] = n - 1;
    oc[x][(y + n - 1) % n] = n - 2;
    pos_awal.first = (x + 2) % n;
    pos_awal.second = (y + n - 1) % n;
  }
  oc[n - 2][0] = n;
  oc[n - 4][0] = n - 3;
  oc[n - 4][n - 1] = 1;
  oc[n - 2][n - 1] = n - 3;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << oc[i][j] << ' ';
    }
    cout << '\n';
  }
}

void solve() {
  int p;
  cin >> p;
  if (p == 2 || p == 3) {
    cout << -1 << '\n';
    return;
  }
  build(p);
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