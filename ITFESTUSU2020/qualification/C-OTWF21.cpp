/**
 * Contest : ITFESTUSU 2020
 * Team    : OTWF21
 * Author  : Muhammad Hasan
 * Problem : C - Kue Tertinggi
 */
#include <bits/stdc++.h>

using namespace std;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc;
  int n;
  cin >> tc;
  while (tc--) {
    cin >> n;
    int x1 = 0, x2 = 0;
    for (int i = 1; i <= n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      x1 += max(a, max(b, c));
      x2 += min(a, min(b, c));
    }
    cout << x2 << " " << x1 << '\n';
  } 

  return 0;
}