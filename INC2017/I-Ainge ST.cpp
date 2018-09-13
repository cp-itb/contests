#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<int> g[N];
bool vis[N], done[N];

int dfs(int v) {
  if (done[v]) return 0;
  done[v] = 1;
  int ret = g[v].size() & 1;
  for (int u : g[v]) {
    ret += dfs(u);
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
    vis[a] = vis[b] = 1;
  }
  vector<int> d;
  for (int i = 1; i < N; i++) if (vis[i] == 1 && !done[i]) {
    d.push_back(dfs(i));
  } 
  sort(d.begin(), d.end());
  int ans = 0;
  while (d.size() > 1) {
    int v = d.back(), u = d[(int)d.size()-2];
    ans++;
    if (u == 0 && v == 0)
      v = 2;
    else if (u == 0 || v == 0)
      v = u + v;
    else
      v = u + v - 2;
    d.pop_back();
    d[(int)d.size()-1] = v;
  }
  ans += d[0]/2;
  printf("%d\n", ans);
  return 0;
}