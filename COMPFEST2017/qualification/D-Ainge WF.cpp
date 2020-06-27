/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : D
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const long long mod = 1e9 + 7;


vector< int > num, low, S, vis;
int cntr, numCC;
vector<int> adj[N], edge[N];
int to[2 * N];

bool bad[N];
int id[N], cnt_cyc;

void tarjanSCC(int v, int bef) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto tmp : adj[v]) {
    int u = to[tmp];
    if ((tmp ^ 1) == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, tmp);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    vector<int> cyc;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cyc.push_back(u);
      if(u == v)
        break;
    }
    if (cyc.size() > 1) {
      //puts("cycle");
      for (auto it : cyc) {
        //printf("%d ", it);
        bad[it] = 1;
      }
      //printf("\n");
    }
  }
}

bool done[N];

void dfs(int now) {
  if (done[now]) return;
  done[now] = 1;
  id[now] = cnt_cyc++;
  for (auto it : adj[now]) if (bad[to[it]]) {
    dfs(to[it]);
  }
}

int a[N], b[N];

int rmq[2 * N][20], h[N], lef[N], rig[N];
vector<int> st;

void pre(int now, int bef) {
  lef[now] = rig[now] = st.size();
  st.push_back(now);
  if (bef != -1) h[now] = h[bef] + 1;
  for (auto it : edge[now]) {
    if (bef == it) continue;
    pre(it, now);
    rig[now] = st.size();
    st.push_back(now);
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int dist(int u, int v) {
  int root = lca(u, v);
  return h[u] + h[v] - 2 * h[root];
}

int main() {
// In MAIN();
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      adj[i].clear();
      edge[i].clear();
    }
    memset(id, -1, sizeof(id));
    memset(bad, 0, sizeof(bad));
    memset(done, 0, sizeof(done));
    cnt_cyc = 0;
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      to[2*i] = u;
      to[2*i+1] = v;
      adj[u].push_back(2*i+1);
      adj[v].push_back(2*i);
      a[i] = u;
      b[i] = v;
    }
    
    num.assign(n + 1, -1);
    low.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    cntr = numCC = 0;
    for(int i = 1; i <= n; i++)
      if(num[i] == -1)
        tarjanSCC(i, -1);
      
    for (int i = 1; i <= n; i++) {
      if (bad[i]) {
        dfs(i);
      }
    }
    
    for (int i = 0; i < n; i++) {
      if (bad[a[i]] && bad[b[i]]) continue;
      if (bad[a[i]]) {
        edge[0].push_back(b[i]);
        edge[b[i]].push_back(0);
      } else if (bad[b[i]]) {
        edge[0].push_back(a[i]);
        edge[a[i]].push_back(0);
      } else {
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
      }
    }
    st.clear();
    pre(0, -1);
    for (int i = 0; i < st.size(); i++) {
      rmq[i][0] = st[i];
    }
    for (int j = 1; (1 << j) <= st.size(); j++) {
      for (int i = 0; i + (1 << j) <= st.size(); i++) {
        rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
      }
    }
    //for (int i = 1; i <= n; i++) printf("%d ", id[i]); printf("\n");
    
    int q;
    scanf("%d", &q);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      if (bad[u] && bad[v]) {
        int d = abs(id[u] - id[v]);
        long long ans = 1LL * d * (cnt_cyc - d) % mod;
        printf("2 %lld\n", ans);
        continue;
      }
      if (bad[u]) u = 0;
      if (bad[v]) v = 0;
      printf("1 %d\n", dist(u, v));
    }
  }

  return 0;
}
