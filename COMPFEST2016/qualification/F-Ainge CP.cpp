/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : F - Friend-Score
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<int> edge[N];
vector<int> s[N];
int par[N], ans[N];

void merge(int u, int v) {
  if (par[u] == par[v]) return;
  u = par[u];
  v = par[v];
  if (s[u].size() < s[v].size()) {
    ans[v] += ans[u];
    for (auto node : s[u]) {
      for (auto it : edge[node]) {
        if (binary_search(s[v].begin(), s[v].end(), it)) {
          ans[v]++;
        }
      }
      par[node] = v;
    }
    vector<int> tmp;
    tmp.resize(s[u].size() + s[v].size());
    merge(s[u].begin(), s[u].end(), s[v].begin(), s[v].end(), tmp.begin());
    s[v] = tmp;
  } else {
    ans[u] += ans[v];
    for (auto node : s[v]) {
      for (auto it : edge[node]) {
        if (binary_search(s[u].begin(), s[u].end(), it)) {
          ans[u]++;
        }
      }
      par[node] = u;
    }
    vector<int> tmp;
    tmp.resize(s[u].size() + s[v].size());
    merge(s[u].begin(), s[u].end(), s[v].begin(), s[v].end(), tmp.begin());
    s[u] = tmp;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      edge[i].clear();
      s[i].clear();
      s[i].push_back(i);
      par[i] = i;
      ans[i] = 0;
    }
    
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    while (q--) {
      int t;
      scanf("%d", &t);
      if (t == 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        merge(u, v);
      } else {
        int u;
        scanf("%d", &u);
        printf("%d\n", ans[par[u]]);
      }
    }
  }
  return 0;
}
