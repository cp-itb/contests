/**
 * Contest : COMPFEST 2018 Final Trial
 * Team    : Tukang Nasi Goreng
 * Author  : Luqman Arifin
 * Problem : B - Kuota Maksimum 
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int cost[N], val[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", cost + i);
    for (int i = 0; i < n; i++) scanf("%d", val + i);
    vector<pair<double, int>> p;
    for (int i = 0; i < n; i++) {
      p.emplace_back((double)val[i] / cost[i], i);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    long long ans = 0;
    for (auto it : p) {
      int i = it.second;
      int get = m / cost[i];
      ans += 1LL * get * val[i];
      m -= 1LL * cost[i] * get;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
