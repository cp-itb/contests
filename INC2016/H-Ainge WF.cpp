/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : H - Negotiation Game
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int a[N];

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
    }
    int temp = min(a[0], a[n - 1]);
    printf("Case #%d: %d\n", tt, temp);
  }
  return 0;
}