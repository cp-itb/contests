/**
 * Contest : VOCOMFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : E - JogJek
 */

#include <bits/stdc++.h>

using namespace std;

const int N =105;

string s[N];
int a[N], b[N];

int main() {
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i] >> a[i] >> b[i];
    }    
    printf("Case #%d:\n", tt);
    for (int i = 0; i < m; i++) {
      int sa, sb, ta, tb;
      cin >> sa >> sb >> ta >> tb;
      int nearest = 2e9, p = -1;
      string name;
      for (int j = 0; j < n; j++) {
        int d = abs(sa - a[j]) + abs(sb - b[j]);
        if (d < nearest) {
          nearest = d;
          p = j;
          name = s[j];
        } else if (d == nearest && s[j] < name) {
          nearest = d;
          p = j;
          name = s[j];
        }
      }
      a[p] = ta;
      b[p] = tb;
      printf("%s\n", name.c_str());
    }
  }

  return 0;
}
