/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : A
 */

#include <bits/stdc++.h>

using namespace std;

set< string > mp;
const int inf = 1e5 + 5;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    bool add = false;
    int n, k;
    mp.clear();
    scanf("%d", &n);
    int mk = 0;
    while (n--) {
      string s;
      cin >> s;
      scanf("%d", &k);
      if (s[0] == 'd')
        mk = max(k, mk);
      for (int i = 0; i < k; i++) {
        cin >> s;
        mp.insert(s);
      }
    }
    int ans = (int)mp.size();
    if (mk == ans)
      ans++;
    printf("%d\n", ans);
  }
  return 0;
}
