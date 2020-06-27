/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : A - Olimpiade Chanek
 */
 
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    cout << c + d - b - a << endl;
  }

  return 0;
}
