/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Wiwit Rifa'i
 * Problem : B - Swap to Sort
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
}

vector<int> vp[N];


int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  memset(p, -1, sizeof p);
  for (int i = 0; i < k; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a; --b;
    merge(a, b);
  }
  for (int i = 0; i < n; ++i)
    vp[find(i)].push_back(i);
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    sort(vp[i].begin(), vp[i].end());
    for (int l = 0, r = (int)vp[i].size() -1; l <= r; ++l, --r) {
      int sum = vp[i][l] + vp[i][r];
      if (sum != n-1)
        ok = 0;
    }
  }
  puts(ok ? "Yes" : "No");
  return 0;
}
