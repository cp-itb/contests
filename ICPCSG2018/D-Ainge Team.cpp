/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Luqman Arifin
 * Problem : D - Cave Exploration
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> adj[N];
int comp[N], sz[N];

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;

void tarjanSCC(int v, int bef) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    ++numCC;
    // printf("%d: ", numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      comp[u] = numCC;
      sz[numCC]++;
      // printf("%d ", u);
      if(u == v)
        break;
    }
    // printf("\n");
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  num.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, 0);
  cntr = numCC = 0;
  for(int i = 0; i<n; i++)
    if(num[i] == -1)
      tarjanSCC(i, -1);

  printf("%d\n", sz[comp[0]]);

  return 0;
}
