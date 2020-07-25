/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Rata
* Author  : Wiwit Rifai
* Problem : C - Connectivity
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

struct Dsu {
  vector<pair<int *, int>> logs;
  vector<int> p;
  int cnt = 0;
  Dsu(int n) {
    p.assign(n, -1);
    cnt = n;
  }

  void assign(int * ptr, int val) {
    logs.emplace_back(ptr, *ptr);
    *ptr = val;
  }

  void reset(int version) {
    while ((int)logs.size() > version) {
      *logs.back().first = logs.back().second;
      logs.pop_back();
    }
  }

  int find(int x) {
    return p[x] < 0 ? x : find(p[x]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (-p[u] > -p[v])
      swap(u, v);
    assign(&p[v], p[v] + p[u]);
    assign(&p[u], v);
    assign(&cnt, cnt-1);
  }
};

char buffer[10];

int main() {
  int n, q;
  scanf("%d %d", &q, &n);
  vector<int> versions;
  Dsu dsu(n);
  versions.push_back(0);
  for (int i = 0; i < q; ++i) {
    scanf("%s", buffer);
    if (buffer[1] == 'O') {
      versions.pop_back();
      dsu.reset(versions.back());
    } else {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      dsu.merge(u, v);
      versions.push_back(dsu.logs.size());
    }
    printf("%d\n", dsu.cnt);
  }
  return 0;
}