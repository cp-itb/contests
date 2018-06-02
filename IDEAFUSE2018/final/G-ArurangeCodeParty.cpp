/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : Arurange Code Party
 * Author  : Dewita Sonya Tarabunga
 * Problem : G - Problem on Array
 */
#include <bits/stdc++.h>

using namespace std;

long long t,n,a[500010];
vector<pair<long long,long long>> v;
pair<long long, long long> x;
long long sm, mk;
const long long MD = 1e9+7;

int main() {
  scanf("%lld", &t);
  for (long long T=1;T<=t;++T) {
    scanf("%lld", &n);
    sm = mk = 0;
    v.clear();
    for (long long i=1;i<=n;++i) {
      scanf("%lld", a+i);
      while (!v.empty() && v.back().first<=a[i]) {
        x = v.back();
        v.pop_back();
        sm += i-x.second;
        sm %= MD;
        mk = max(mk, i-x.second);
      }
      v.push_back({a[i], i});
    }
    for (int i=1;i<v.size();++i) {
      for (int j=v[i-1].second;j<=n;++j) {
        if (a[j]==v[i].first) {
          sm += j-v[i-1].second;
          sm %= MD;
          mk = max(mk, j-v[i-1].second);
          break;
        }
      }
    }
    printf("Case #%lld: %lld %lld\n", T, mk, sm);
  }
}