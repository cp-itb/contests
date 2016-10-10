/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Ahmad Zaky
 * Problem : I - Irpin's Walk
 */

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 100100
#define INF 1000000000

int ntc, n, m, a, b;
vector<pii> adj[MAXN];
int cost[MAXN][33];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d", &n, &m, &a, &b);
		FOR(i, 1, n) {
			adj[i].clear();
		}
		FOR(i, 1, m) {
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			adj[x].PB(MP(y, w));
			adj[y].PB(MP(x, w));
		}
		priority_queue<pair<int, pii> > pq;
		FOR(i, 1, n) FOR(j, 0, 30) {
			cost[i][j] = INF;
		}
		cost[a][0] = 0;
		pq.push(MP(0, MP(a, 0)));
		while (!pq.empty()) {
			pair<int, pii> top = pq.top(); pq.pop();
			int ncost = -top.A;
			int v = top.B.A, nedge = top.B.B;
			if (cost[v][nedge] < ncost) continue;
			FORIT(it, adj[v]) {
				int xcost = ncost + it->B;
				int xedge = nedge + 1;
				if (xedge > 30) xedge = 30;
				if (xcost < cost[it->A][xedge]) {
					cost[it->A][xedge] = xcost;
					pq.push(MP(-xcost, MP(it->A, xedge)));
				}
			}
		}
		int ans = INF;
		FOR(i, 0, 30) {
			int ncost = cost[b][i];
			if ((1 << i) <= ncost) {
				ncost <<= 1;
			}
			MN(ans, ncost);
		}
		if (ans == INF) ans = -1;
		printf("Case #%d: %d\n", itc, ans);
	}
	
	return 0;
}