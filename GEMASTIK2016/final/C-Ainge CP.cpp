/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : C
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (n >= m)
      puts("0");
    else {
      long long ans = 1;
      for (int i = 1; i <= n; i++) {
        ans = (ans * i) % m;
      }
      printf("%lld\n", ans);
    }

  }
  return 0;
}
