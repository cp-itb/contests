/**
 * Contest : COMPFEST 2017 Final
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel Wiguna
 * Problem : H - Perjalanan Aneh
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <cstring>
#include <map>

#define piiihapus pair<int,pair<int,int> >
#define plll pair<long long,pair<long long,long long> >
#define pll pair<long long, long long>
#define mp(a,b,c) make_pair(a, make_pair(b,c))
#define fi first
#define se second.first
#define th second.second
#define pb push_back
#define ll long long
#define MAXN 100005
#define INF 1e9
#define EPS 1e-9
#define ceili(a,b) (a/b + ((a%b == 0)? 0 : 1))

using namespace std;

ll n,m;
ll u,v,b,x;
vector<plll> adj[50005];
priority_queue<plll, vector<plll>, greater<plll> > pq;
ll dist[50005];

void percase() {
  scanf("%lld%lld",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%lld%lld%lld%lld",&u,&v,&b,&x);
    adj[u].pb(mp(v,b,x));
    adj[v].pb(mp(u,b,x));
  }
  while (!pq.empty()) { pq.pop(); }

  pq.push(mp(0, 1, 0));
  memset(dist, -1, sizeof dist);

  while (!pq.empty()) {
    plll top = pq.top();
    pq.pop();

    if (dist[top.se] == -1 || dist[top.se] > top.fi) {
      long long tn = top.fi;
      dist[top.se] = tn;
      if (tn < 0) { while (true) { int a = 0; } }
      //printf("%lld %lld\n", top.se, tn);
      for (int i=0; i<adj[top.se].size(); i++) {
        plll ne = adj[top.se][i];
        if (ne.th == 0) {
          pq.push(mp((tn + max(1LL, ne.se)), ne.fi, 0LL));
        } else {
          pq.push(mp((tn + 1LL + max(0LL, ceili((ne.se-1LL),ne.th) - tn)), ne.fi, 0LL));
        }
      }
    }
  }

  for (int i=0; i<=n; i++) {
    adj[i].clear();
  }

  printf("%lld\n", dist[n]);
  if (dist[n] < 0) { while (true) { int a = 0; } }

}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}