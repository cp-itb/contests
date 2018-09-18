/**
 * Contest : COMPFEST 2018 Final
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : G - Pertempuran Kuda   
 */

/*
  COMPETITION
  Is the time you kill. The ill you will create.
  The knowledge you neglect to learn.
  The connection you fail to build.
  the health you sacrifice along the path.
  Your inability to generate ideas.
  The people around you who dont support and love.
  Your effort and whatever god you curse for badluck.
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
