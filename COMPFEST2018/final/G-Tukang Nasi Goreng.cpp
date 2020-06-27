/**
 * Contest : COMPFEST 2018 Final
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : G - Pertempuran Kuda   
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int x = abs(a-c), y = abs(b-d);
    if (x > y) swap(x, y);
    puts((x == 1 && y == 2) ? "YA" : "TIDAK");
  }  
  return 0; 
}
