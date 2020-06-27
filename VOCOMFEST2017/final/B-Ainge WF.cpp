/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Aufar Gilbran
 * Problem : B - Amazing Labyrinth
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 500
int vis[MAXN+5][1<<17];
vector<int> edge[MAXN+5], req[MAXN+5], sac[MAXN+5];

int main() {
  int V, E, N;
  scanf("%d%d%d", &V, &E, &N);
  int ans = 0;
  for (int i = 0; i < E; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for (int i = 1; i <= V; ++i) {
    int nreq;
    scanf("%d", &nreq);
    for (int j = 0; j < nreq; ++j) {
      int x;
      scanf("%d", &x);
      req[i].push_back(x);
    }
  }
  for (int i = 1; i <= V; ++i) {
    int nreq;
    scanf("%d", &nreq);
    for (int j = 0; j < nreq; ++j) {
      int x;
      scanf("%d", &x);
      sac[i].push_back(x);
    }
  }

  queue<pair<int,int> > Q;
  Q.push(make_pair(1, 0));
  while (!Q.empty()) {
    int v = Q.front().first;
    int mask = Q.front().second;
    Q.pop();
    bool fail = false;
    if (vis[v][mask]) continue;
    vis[v][mask] = 1;
    if (v == V) {
      int cand = N;
      for (int i = 0; i < N; ++i) {
        if (mask & (1<<i)) {
          cand--;
        }
      }
      ans = max(ans, cand);
    }
    for (int i = 0; i < req[v].size(); ++i) {
      int num = req[v][i]-1;
      if (mask & (1<<num)) {
        fail = true;
        break;
      }
    }
    if (fail) continue;
    for (int i = 0; i < edge[v].size(); ++i) {
      int nv = edge[v][i];
      int nmask = mask;
      for (int j = 0; j < sac[v].size(); ++j) {
        int num = sac[v][j]-1;
        nmask |= (1<<num);
      }
      Q.push(make_pair(nv, nmask));
    }
  }

  printf("%d\n", ans);
  return 0;
}
