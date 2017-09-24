/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : A - Cube
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    long long n;
    scanf("%lld", &n);
    long long tot = n * n * n;
    long long a = (n - 2)*(n - 2)*(n - 2);
    long long b = 6 * (n - 2) * (n - 2);
    long long d = 8;
    long long c = tot - a - b - d;
    printf("Case #%d: %lld %lld %lld %lld\n", tt, a, b, c, d);
  } 
  return 0;
}
