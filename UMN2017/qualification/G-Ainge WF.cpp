/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : G - Strategi Tentara
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    int k = (n-1 + m - 1)/m;
    printf("Case #%d: %d %d\n", tc, k, n-k);
  }
  return 0;
}
