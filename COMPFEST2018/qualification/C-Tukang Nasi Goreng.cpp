/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : Tukang Nasi Goreng
 * Author  : Luqman Arifin
 * Problem : C - Mencari Tempat 
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
const int inf = 1e9;

vector<int> edge[N];
vector<int> lom[N];
int lon[N];

int ans[N];

void upd(int& at, int val) {
  at = max(at, val);
}

int beri_edge_sebarkan_anak(int now, int bef) {
  vector<int> lef, rig;
  lef.assign(edge[now].size(), -inf);
  rig.assign(edge[now].size(), -inf);
  for (int i = 0; i < edge[now].size(); i++) {
    auto it = edge[now][i];
    if (it == bef) continue;
    auto ret = beri_edge_sebarkan_anak(it, now);
    if (i - 1 >= 0) {
      upd(lef[i - 1], ret + 1);
    }
    if (i + 1 < edge[now].size()) {
      upd(rig[i + 1], ret + 1);
    }
    lon[now] = max(lon[now], ret);
  }
  for (int i = (int) edge[now].size() - 2; i >= 0; i--) {
    upd(lef[i], lef[i + 1]);
  }
  for (int i = 1; i < edge[now].size(); i++) {
    upd(rig[i], rig[i - 1]);
  }
  for (int i = 0; i < edge[now].size(); i++) {
    if (edge[now][i] == bef) continue;
    upd(ans[edge[now][i]], max(lef[i], rig[i]));
  }

  return max(ans[now], lon[now]) + 1;
}

void beri_node(int now, int bef) {
  for (auto it : edge[now]) {
    if (it == bef) continue;
    upd(ans[it], ans[now] + 1);
    beri_node(it, now);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      edge[i].clear();
      lom[i].clear();
      ans[i] = -inf;
      lon[i] = -inf;
    }

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      lom[i].assign(edge[i].size(), -inf);
    }
    for (int i = 0; i < m; i++) {
      int v;
      scanf("%d", &v);
      ans[v] = 0;
    }
    beri_edge_sebarkan_anak(1, 0);
    //for (int i = 1; i <= n; i++) printf("%d: ans %d lon %d\n", i, ans[i], lon[i]);
    beri_node(1, 0);
    for (int i = 1; i <= n; i++) upd(ans[i], lon[i]);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      // printf("%d: %d\n", i, ans[i]);
      if (ans[i] <= k) {
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }

  return 0;
}
