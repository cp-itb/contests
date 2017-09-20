/**
 * Contest : VOCOMFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : A - Goats Competition
 */

#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int ma = 0;
    for (int i = 0; i < 4; i++) {
      scanf("%d", a+i);
      ma = max(ma, a[i]);
    }
    int r;
    scanf("%d", &r);
    printf("Case #%d: %s\n", tc, ma > r ? "new record!" : "no new record");
  }
  return 0;
}
