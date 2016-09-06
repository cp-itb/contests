/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : hehehe
 * Author  : Ahmad Zaky
 * Problem : F - Friend-Score
 */

/* DELAPAN.3gp */
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

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MAXN 100100

int ntc;

int n, m, q, u[MAXN], v[MAXN];
int qp[MAXN], qt[MAXN][2];

int f[MAXN], l[MAXN], r[MAXN];
vector<int> mmap[MAXN];

int p[MAXN], ans[MAXN];

int findSet(int x) {
	if (p[x] == x) {
		return x;
	} else {
		return p[x] = findSet(p[x]);
	}
}

void join(int x, int y) {
	int sx = findSet(x);
	int sy = findSet(y);
	p[sy] = sx;
}

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &q);
		FOR(i, 1, m) {
			scanf("%d%d", &u[i], &v[i]);
		}
		FOR(i, 1, q) {
			scanf("%d", &qp[i]);
			if (qp[i] == 1) {
				scanf("%d%d", &qt[i][0], &qt[i][1]);
			} else {
				scanf("%d", &qt[i][0]);
			}
		}

		// RESET DULU BISA KALI
		FOR(i, 0, q + 1) {
			mmap[i].clear();
			f[i] = 0;
		}

		FOR(i, 1, m) {
			l[i] = 1;
			r[i] = q + 1;
			mmap[(q + 2) / 2].PB(i);
		}

		int count = 0;
		while (true) {
			// printf("iterasi ke-%d\n", ++count);
			// reset DSU
			FOR(i, 1, n) {
				p[i] = i;
			}

			bool done = true;

			// rerun query
			FOR(s, 1, q) {
				if (qp[s] == 1) {
					join(qt[s][0], qt[s][1]);
				}

				while (!mmap[s].empty()) {
					int now = mmap[s].back(); mmap[s].pop_back();
					if (findSet(u[now]) == findSet(v[now])) {
						r[now] = s;
					} else {
						l[now] = s + 1;
					}

					if (l[now] < r[now]) {
						int m = (l[now] + r[now]) / 2;
						mmap[m].PB(now);
						done = false;
					}
				}
			}

			if (done) break;
		}

		FOR(i, 1, m) {
			if (l[i] <= q) {
				f[l[i]]++;
				// assert(qp[l[i]] == 1);
			}
			// printf("%d [%d..%d]: %d\n", i, u[i], v[i], l[i]);
		}

		// reset DSU lagi
		FOR(i, 1, n) {
			p[i] = i;
			ans[i] = 0;
		}
		FOR(i, 1, q) {
			if (qp[i] == 1) {
				int x = qt[i][0], y = qt[i][1];
				int sx = findSet(x), sy = findSet(y);
				p[sy] = sx;
				ans[sx] += ans[sy];
				ans[sx] += f[i];
			} else {
				printf("%d\n", ans[findSet(qt[i][0])]);
			}
		}
	}

	return 0;
}
