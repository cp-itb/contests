/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : Tukang Nasi Goreng
 * Author  : Luqman Arifin
 * Problem : A - Origami Tempel 
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

vector<int> all;
vector<int> at[N];
int a[N], b[N];
map<int, int> mp;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    all.clear();
    for (int i = 0; i < N; i++) at[i].clear();
    mp.clear();
    for (int i = 0; i < N; i++) par[i] = i;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", a + i, b + i);
      all.push_back(a[i]);
      all.push_back(b[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < all.size(); i++) mp[all[i]] = i;
    for (int i = 0; i < n; i++) {
      at[mp[a[i]]].push_back(i);
      at[mp[b[i]]].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < all.size(); i++) {
      set<int> s;
      for (auto it : at[i]) s.insert(find(it));
      ans += 1LL * (s.size() - 1) * all[i];
      auto root = *(s.begin());
      for (auto it : s) merge(it, root);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
