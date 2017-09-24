/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : B
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int a[N];

// selisih - lebar
int brute(int p, int until, vector<pair<int, int>>& all, int diff, int lebar) {
  if (p == until) {
    all.emplace_back(diff, lebar);
    return 0;
  }
  brute(p + 1, until, all, diff + a[p], lebar);
  brute(p + 1, until, all, diff - a[p], lebar);
  int v = brute(p + 1, until, all, diff, lebar + a[p]);
  return v + a[p];
}

int get(int tot, int diff, int lebar) {
  return (tot - lebar - diff) / 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    vector<pair<int, int>> lef, rig;
    int tlef = brute(0, n / 2, lef, 0, 0);
    int trig = brute(n / 2, n, rig, 0, 0);
    sort(lef.begin(), lef.end());
    sort(rig.begin(), rig.end());
    lef.resize(distance(lef.begin(), unique(lef.begin(), lef.end())));
    rig.resize(distance(rig.begin(), unique(rig.begin(), rig.end())));
    //for (auto it : lef) printf("%d %d\n", it.first, it.second);
    
    long long ans = 0;
    int j = rig.size() - 1;
    for (int i = 0; i < lef.size(); i++) {
      while (-lef[i].first < rig[j].first && j > 0) j--;
      while (j > 0 && -lef[i].first == rig[j - 1].first) {
        long long now = 1LL * (get(tlef, lef[i].first, lef[i].second) + get(trig, rig[j].first, rig[j].second)) * (lef[i].second + rig[j].second);
        long long nex = 1LL * (get(tlef, lef[i].first, lef[i].second) + get(trig, rig[j-1].first, rig[j-1].second)) * (lef[i].second + rig[j-1].second);
        if (nex > now) j--;
        else break;
      }
      if (-lef[i].first == rig[j].first) {
        long long now = 1LL * (get(tlef, lef[i].first, lef[i].second) + get(trig, rig[j].first, rig[j].second)) * (lef[i].second + rig[j].second);
        ans = max(ans, now);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
