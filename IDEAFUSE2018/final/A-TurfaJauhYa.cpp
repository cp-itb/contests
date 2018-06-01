/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Turfa Auliarachman
 * Problem : A - Biutiful Number
 */
#include <bits/stdc++.h>
using namespace std;

bool x[1000010];

int main() {
  memset(x, false, sizeof x);

  int aa = 1;
  int bb = 2;
  x[1] = true;
  while (aa <= 1000000) {
    aa += bb;
    x[aa] = true;
    bb++;
  }
  int t;
  cin >> t;
  for (int tc=1; tc <= t; tc++) {
    cout << "Case #" << tc << ": " << endl;
    int n;
    cin >> n;
    if (x[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}