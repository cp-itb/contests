/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Jauhar Arifin
 * Problem : H - Captain Kaban
 */
#include <bits/stdc++.h>
using namespace std;

int t,n,mi,ma,total;

int main() {
  scanf("%d", &t);
  for (int tc=1; tc<=t; tc++) {
    scanf("%d", &n);
    total=0;
    mi=2000000000;
    ma=-2000000000;
    for (int i=0; i<10; i++) {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      x = x+y+z;
      total += x;
      mi = min(x,mi);
    }
    for (int i=0; i<n; i++) {
      int x,y,z;
      scanf("%d%d%d", &x,&y,&z);
      x = x+y+z;
      ma = max(ma, x);
    }
    if (ma > mi)
      total = total - mi + ma;
    printf("Case #%d: %d\n", tc, total);
  }
}