/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : H - Perjalanan Aneh
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e12 + 4;

struct edge {
  long long x, b;
  int u;
  edge(int u, long long x, long long b) : u(u), x(x), b(b) {}
  long long calc(long long t) {
    return max(t+1, t * (1-x) + b);
  }
};

vector<edge> g[N];
int n, m;
long long d[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      long long x, b;
      scanf("%d %d %lld %lld", &u, &v, &b, &x);
      u--; v--;
      g[u].push_back(edge(v, x, b));
      g[v].push_back(edge(u, x, b));
    }
    fill(d, d+n, inf);
    set<pair< long long, int> > st;
    d[0] = 0;
    st.insert(make_pair(0, 0));
    while (!st.empty()) {
      set<pair<long long, int> >::iterator it = st.begin();
      int v = it->second;
      st.erase(it);
      for (edge e : g[v]) {
        long long nd = e.calc(d[v]);
        if (e.x) {
          long long z = (e.b - 1) / e.x;
          for (long long y = -1; y <= 1; y++) {
            if (z+y >= d[v])
              nd = min(nd, e.calc(z+y));
          }
        }
        if (d[e.u] > nd) {
          st.erase(make_pair(d[e.u], e.u));
          d[e.u] = nd;
          st.insert(make_pair(d[e.u], e.u));
        }
      }
    }
    printf("%lld\n", d[n-1]);
  }
  return 0;
}
