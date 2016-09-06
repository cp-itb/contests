/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : hehehe
 * Author  : Ahmad Zaky
 * Problem : F - Kartu Truf
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

db ans;

int ntc;
int v[111][111], t[111], nc[111], cc[111][111], p[111];
char c[111][111];

void dfs(int t, int c, int x, db p, int given) {
	// printf("dfs(%d, %d, %d, %g)\n", t, c, x, p);
	if (x > 13) {
		bool win = true;
		REP(i, 3) {
			if (nc[i] && cc[i][0] > c) {
				win = false;
				break;
			}
		}
		if (win) {
			ans += p;
		}
	} else {
		if (v[t][x]) {
			dfs(t, c, x + 1, p, given);
		} else {
			REP(i, 3) {
				db newp = p * (13 - nc[i]) / (39 - given);
				cc[i][nc[i]++] = x;
				dfs(t, c, x + 1, newp, given + 1);
				nc[i]--;
			}
		}
	}
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		RESET(v, 0);
		REP(i, 13) {
			scanf("%s", c[i]);
			// printf("[%s]\n", c[i]);
			// fflush(stdout);
			if (c[i][1] == 'D') {
				t[i] = 0;
			} else if (c[i][1] == 'C') {
				t[i] = 1;
			} else if (c[i][1] == 'H') {
				t[i] = 2;
			} else if (c[i][1] == 'S') {
				t[i] = 3;
			} else {
				assert(false);
			}
			if ('2' <= c[i][0] && c[i][0] <= '9') {
				p[i] = c[i][0] - '0';
			} else if (c[i][0] == 'T') {
				p[i] = 10;
			} else if (c[i][0] == 'J') {
				p[i] = 11;
			} else if (c[i][0] == 'Q') {
				p[i] = 12;
			} else if (c[i][0] == 'K') {
				p[i] = 13;
			} else if (c[i][0] == 'A') {
				p[i] = 14;
			} else {
				assert(false);
			}
			// puts("DONE");
			// fflush(stdout);

			p[i]--;
			v[t[i]][p[i]] = 1;
		}
		REP(i, 13) {
			ans = 0;
			REP(j, 3) {
				nc[j] = 0;
			}
			// printf("DFS STARTED FOR [%s]\n", c[i]);
			// fflush(stdout);
			dfs(t[i], p[i], 1, 1.0, 0);
			// printf("DFS FINISHED FOR [%s]\n", c[i]);
			// fflush(stdout);
			printf("%s: %.5lf%%\n", c[i], ans * 100);
		}
		if (itc != ntc) {
			putchar('\n');
		}
	}

	return 0;
}
