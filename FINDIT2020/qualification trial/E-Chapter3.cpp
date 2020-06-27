/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : E - Bilangan Kompleks
 */
#include <bits/stdc++.h>
 
using namespace std;
 
int a, b, c, d;
 
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  cin >> a >> b >> c >> d;
  cout << a * c - b * d << " " << (a * d + b * c) << "i" << '\n';
 
  return 0;
} 