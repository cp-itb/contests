#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

const bool debug = false;

int n,m;
int a,b,x,d;
vector<int> adj[100005];
int dist[100005];
int cnt[100005];
queue<int> q;

int main() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<n-1; i++) {
    scanf("%d%d",&a,&b);
    adj[a-1].pb(b-1);
    adj[b-1].pb(a-1);
  }
  memset(cnt, 0, sizeof cnt);
  while (m--) {
    scanf("%d%d",&a,&b); a--;

    if (b == 0) cnt[a]++;
    else {
      memset(dist, -1, sizeof dist);
      dist[a] = 0;
      q.push(a);

      while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i=0; i<adj[cur].size(); i++) {
          int next = adj[cur][i];
          if (dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            if (dist[next] == b) {
              cnt[next]++;
            } else {
              q.push(next);
            }
          }
        }
      }
    }
  }
  int maks = 0;
  for (int i=0; i<n; i++) {
    maks = max(cnt[i], maks);
  }
  printf("%d\n", maks);
}