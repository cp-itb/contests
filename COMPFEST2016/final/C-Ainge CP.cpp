/**
 * Contest : COMPFEST 2016 Final
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : C
 */

#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8 + 5;

struct Edge {
  int from , to, cap, flow, cost;
  Edge(int from, int to, int cap, int flow, int cost) :
    from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};

struct MCMF {
  int n, s, t;
  vector< vector< int > > adj;
  vector< int > par;
  vector< Edge > vEdge;
  vector< long long > dist;
  MCMF(int n, int s, int t) : n(n), s(s), t(t), adj(n) {
  }
  void addEdge(int from, int to, int cap, int cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }
  long long augment(int v, int minflow = inf) {
    if (v == s) {
      return minflow;
    }
    if (par[v] < 0)
      return 0;
    long long flow;
    Edge &e = vEdge[par[v]];
    if (v == e.from) {
      flow = augment(e.to, min(minflow, e.flow));
      e.flow -= flow;
    }
    else {
      flow = augment(e.from, min(minflow, e.cap - e.flow));
      e.flow += flow;
    }
    return flow;
  }
  long long findingPath() {
    // dijsktra
    set < pair< long long , int > > st;
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[s] = 0;
    st.insert(make_pair(dist[s], s));
    while (!st.empty()) {
      set < pair< long long , int > >::iterator it = st.begin();
      int v = it->second;
      // cerr << v << endl;
      st.erase(it);
      for (int i = 0; i < adj[v].size(); i++) {
        Edge &e = vEdge[adj[v][i]];
        if (e.from == v) {
          if (e.cap > e.flow && dist[e.to] > dist[v] + e.cost) {
            st.erase(make_pair(dist[e.to], e.to));
            dist[e.to] = dist[v] + e.cost;
            st.insert(make_pair(dist[e.to], e.to));
            par[e.to] = adj[v][i];
          }
        }
        else {
          if (e.flow > 0 && dist[e.from] > dist[v] - e.cost) {
            st.erase(make_pair(dist[e.from], e.from));
            dist[e.from] = dist[v] - e.cost;
            st.insert(make_pair(dist[e.from], e.from));
            par[e.from] = adj[v][i];
          }
        }
      }
    }
    // cerr << par[t] << endl;
    return augment(t, inf);
  }

  pair< long long, long long > EdmondKarp() {
    long long maxflow = 0, mincost = 0;
    long long flow = 0;
    while (flow = findingPath()) {
      // cerr << flow << endl;
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }
};

int x[50][50], id[50][50];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int r, c;
    scanf("%d %d", &r, &c);
    int last = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", x[i]+j);
        id[i][j] = last++;
      }
    }
    int s = last++, t = last++;
    MCMF mcmf(last, s, t);
    // // cerr << "hello" << endl;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (i) {
          int u = id[i][j], v = id[i-1][j];
          if ((i + j) & 1)
            swap(u, v);
          mcmf.addEdge(u, v, 1, x[i][j] != x[i-1][j]);
        }
        if (j) {
          int u = id[i][j], v = id[i][j-1];
          if ((i + j) & 1)
            swap(u, v);
          mcmf.addEdge(u, v, 1, x[i][j] != x[i][j-1]);
        }
        if (((i+j) & 1) == 0) {
          mcmf.addEdge(s, id[i][j], 1, 0);
        }
        else {
          mcmf.addEdge(id[i][j], t, 1, 0);
        }
      }
    }
    // // cerr << "pre" ;
    pair< long long, long long > res = mcmf.EdmondKarp();
    assert(res.second == r * c/2);
    // // cerr << res.second << endl;
    printf("%lld\n", res.first);
  }
  return 0;
}