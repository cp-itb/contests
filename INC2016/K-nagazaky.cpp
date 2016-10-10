/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Ahmad Zaky
 * Problem : K - Operations on Matrix
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

#define MAXN 111

int ntc, n, m, q, a[MAXN][MAXN], temp[MAXN][MAXN];

char task[100], taskd[100];
int r, c, s, ra, ca, rb, cb;

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &q);
		FOR(i, 1, n) FOR(j, 1, m) {
			scanf("%d", &a[i][j]);
		}
		FOR(iq, 1, q) {
			scanf("%s%s", task, taskd);
			if (strcmp(task, "rotate") == 0) {
				scanf("%d%d%d", &r, &c, &s);
				if (strcmp(taskd, "cw") == 0) {
					FOR(i, r, r + s) FOR(j, c, c + s) {
						temp[i][j] = a[i][j];
					}
					FOR(i, r, r + s) FOR(j, c, c + s) {
						a[i][j] = temp[r + c + s - j][c + i - r];
					}
				} else {
					REP(x, 3) {
						FOR(i, r, r + s) FOR(j, c, c + s) {
							temp[i][j] = a[i][j];
						}
						FOR(i, r, r + s) FOR(j, c, c + s) {
							a[i][j] = temp[r + c + s - j][c + i - r];
						}
					}
				}
			} else {
				scanf("%d%d%d%d", &ra, &ca, &rb, &cb);
				if (strcmp(taskd, "x") == 0) {
					for (int il = ra, ir = rb; il < ir; ++il, --ir) {
						FOR(i, ca, cb) {
							swap(a[il][i], a[ir][i]);
						}
					}
				} else {
					for (int il = ca, ir = cb; il < ir; ++il, --ir) {
						FOR(i, ra, rb) {
							swap(a[i][il], a[i][ir]);
						}
					}
				}
			}
		}
		printf("Case #%d:\n", itc);
		FOR(i, 1, n) {
			FOR(j, 1, m) {
				printf("%d", a[i][j]);
				if (j == m) {
					putchar('\n');
				} else {
					putchar(' ');
				}
			}
		}
	}
	
	return 0;
}