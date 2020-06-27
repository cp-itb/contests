/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : A
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 255;

int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        ans += a[i][j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
