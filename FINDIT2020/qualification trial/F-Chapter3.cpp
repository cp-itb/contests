/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : F - Saklar Ajaib
 */
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ans & 1) v[i] ^= 1;
    if (v[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
 
  return 0;
} 