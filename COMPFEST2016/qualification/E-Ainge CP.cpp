/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : E - Efek Domino
 */

#include <bits/stdc++.h>

using namespace std;

const long long base = 1e5;

vector < long long > ans;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    ans.clear();
    ans.push_back(1);
    for (int i = 1; i <= n; i++) {
      long long mul = i/2 + 1;
      long long now = 0;
      for (int j = 0; j < ans.size(); j++) {
        now = now + ans[j] * mul;
        ans[j] = now % base;
        now /= base;
      }
      while(now) {
        ans.push_back(now % base);
        now /= base;
      }
    }
    printf("%lld", ans.back());
    for (int i = (int)ans.size() - 2; i >= 0; i--)
      printf("%05lld", ans[i]);
    printf("\n");
  }
  return 0;
}