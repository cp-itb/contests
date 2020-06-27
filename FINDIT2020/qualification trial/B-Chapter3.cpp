/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : B - Anak Kadal Belajar Menghitung
 */
#include <bits/stdc++.h>
 
using namespace std;
 
int tc;
int n;
 
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<int> v;
    for (int i = n + 1; i <= n + 100; i++) {
      if (i & 1) {
        v.push_back(i);
      }
      if ((int) v.size() == 3) break;
    }
    for (int i = 0; i < 3; i++) {
      cout << v[i] << (i == 2 ? '\n' : ' ');
    }
  }
 
  return 0;
} 