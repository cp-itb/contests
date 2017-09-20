/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : H - Traktiran Perpisahan :(
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    double p, d, i;
    cin >> d >> p >> i;
    i += 100;
    i /= 100;
    int ans = 0;
    while (d < p) {
      d *= i;
      ans++;
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
