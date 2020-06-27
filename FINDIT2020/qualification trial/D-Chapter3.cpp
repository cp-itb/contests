/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : D - Anak Pasar Jangkrik
 */
#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  int x1, x2, v1, v2;
  cin >> x1 >> v1 >> x2 >> v2;
  if (x1 == x2) {
    cout << "YES" << '\n';
    return 0;
  }
  if (v1 == v2) {
    cout << "NO" << '\n';
    return 0;
  }
  if (abs(x1 - x2) % abs(v1 - v2) == 0) {
    int res = (x1 - x2) / (v2 - v1);
    cout << (res >= 0 ? "YES" : "NO") << '\n';
  } else {
    cout << "NO" << '\n';
  }
 
  return 0;
} 