/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : G
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int dp[N][4];
vector< int > adj[N];
vector< int > h[N], m[N], hh[N], mm[N];

void dfs(int v, int p = -1) {
  // cerr << v << endl;
  dp[v][0] = dp[v][1] = 1;
  dp[v][2] = dp[v][3] = 0;
  h[v].clear();
  hh[v].clear();
  m[v].clear();
  mm[v].clear();
  for (int u : adj[v]) if (u != p) {
    dfs(u, v);
    dp[v][1] += min(dp[u][3], dp[u][2]);
    dp[v][2] += min(dp[u][0], dp[u][1]);
    h[v].push_back(min(dp[u][2], dp[u][3]));
    m[v].push_back(min(dp[u][0], dp[u][1]));
    mm[v].push_back(dp[u][1]);
    hh[v].push_back(dp[u][2]);
  }
  // // cerr << "ok" << endl;

  // cerr << 'd' << endl;
  if (h[v].empty())
    return;
  int ansh, ansm,summ, sumh;
  summ = sumh = 0;
  for (int i = 0; i < h[v].size(); i++) {
    mm[v][i] += sumh;
    hh[v][i] += summ;
    summ += m[v][i];
    sumh += h[v][i];
  }
  ansh = summ;
  ansm = sumh;
  // cerr << ansh << " " << ansm << endl;
  summ = sumh = 0;
  for (int i = (int)h[v].size()-1; i >= 0; i--) {
    ansm = min(mm[v][i] + sumh, ansm);
    ansh = min(hh[v][i] + summ, ansh);
    summ += m[v][i];
    sumh += h[v][i];
  }
  dp[v][0] += ansm;
  dp[v][3] += ansh;
  // cerr << 'd' << endl;
  // cerr << v << " ";
  // for (int i = 0; i < 4; i++)
  //   printf("%d ", dp[v][i]);
  // printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b); 
      a--; b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(0, -1);
    // cerr << "why" << endl;
    int ans = N;
    for (int i = 0; i < 4; i++)
      ans = min(ans, dp[0][i]);
    printf("%d\n", ans);
  }

  return 0;
}
