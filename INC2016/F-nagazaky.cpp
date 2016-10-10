/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Ahmad Zaky
 * Problem : F - Shady Antique Collector
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

#define MAXN 33
#define MAXMASK 1111

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int ntc, r, c, k, m;
char buffer[MAXN], grid[MAXN][MAXN];

int wm[MAXN][MAXN][MAXMASK], dp[2][MAXMASK], cost[MAXMASK];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d", &r, &c, &k, &m);
		pii start;
		FOR(i, 1, r) {
			scanf("%s", buffer);
			FOR(j, 1, c) {
				grid[i][j] = buffer[j - 1];
				if (grid[i][j] == 'E') {
					start = MP(i, j);
				}
			}
		}
		FOR(i, 1, r) grid[i][0] = grid[i][c + 1] = '#';
		FOR(j, 1, c) grid[0][j] = grid[r + 1][j] = '#';

		queue<pair<pii, int> > q;
		RESET(wm, -1);
		q.push(MP(start, 0));
		wm[start.A][start.B][0] = 0;
		while (!q.empty()) {
			pair<pii, int> top = q.front(); q.pop();
			int nr = top.A.A, nc = top.A.B;
			int mask = top.B;
			int nw = wm[nr][nc][mask];
			REP(d, 4) {
				int xr = nr + dir[d][0];
				int xc = nc + dir[d][1];
				if (grid[xr][xc] == '#') continue;
				int xmask = mask;
				if ('0' <= grid[xr][xc] && grid[xr][xc] <= '9') {
					xmask |= 1 << (grid[xr][xc] - '0');
				}
				if (wm[xr][xc][xmask] == -1) {
					wm[xr][xc][xmask] = nw + 1;
					q.push(MP(MP(xr, xc), xmask));
				}
				// adds possibility to not take the treasure as well
				if (wm[xr][xc][mask] == -1) {
					wm[xr][xc][mask] = nw + 1;
					q.push(MP(MP(xr, xc), mask));
				}
			}
		}

		RESET(dp, -1);
		int s = 0;
		REP(mask, 1 << 10) {
			dp[s][mask] = cost[mask] = wm[start.A][start.B][mask];
		}
		FOR(t, 2, m) {
			RESET(dp[1 - s], -1);
			REP(mask, 1 << 10) {
				dp[1 - s][mask] = dp[s][mask];
				FOR(pmask, 0, mask) {
					if ((pmask & mask) == pmask) {
						if (dp[s][pmask] == -1 || cost[pmask ^ mask] == -1) continue;
						int dpnow = max(dp[s][pmask], cost[pmask ^ mask]);
						if (dp[1 - s][mask] == -1 || dp[1 - s][mask] > dpnow) {
							dp[1 - s][mask] = dpnow;
						}
					}
				}
			}
			REP(mask, 1 << 10) {
				dp[s][mask] = dp[1 - s][mask];
			}
			s = 1 - s;
		}

		int ans = -1;
		REP(mask, 1 << 10) {
			if (__builtin_popcount(mask) < k || dp[s][mask] == -1) continue;
			if (ans == -1 || ans > dp[s][mask]) {
				ans = dp[s][mask];
			}
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	
	return 0;
}