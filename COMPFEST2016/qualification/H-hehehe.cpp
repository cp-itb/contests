/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : hehehe
 * Author  : Ahmad Zaky
 * Problem : H - Badak Lompat
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

#define MOD 1000000007

int ntc, n, a[3][55][55];
int dp[2][55 * 55 * 55];

int calc(int r1, int r2, int r3) {
	return n * n * r1 + n * r2 + r3;
}

int nexttttt[2][2] = {{0, -1}, {-1, 0}};

int main(){
	scanf("%d", &ntc);
	// ntc = 1;

	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		// n = 50;
		REP(k, 3) {
			REP(i, n) REP(j, n) {
				scanf("%d", &a[k][i][j]);
			}
		}

		ll count = 0;

		int state = 0;
		dp[state][0] = 1;
		if ((a[0][0][0] < a[1][0][0] && a[1][0][0] < a[2][0][0]) || (a[0][0][0] > a[1][0][0] && a[1][0][0] > a[2][0][0])) {
			dp[state][0] = 0;
		}

		FOR(s, 1, 2 * n - 2) {
			int r = s, c = 0;
			if (r >= n) {
				c = r - n + 1;
				r = n - 1;
			}
			int t = abs(r - c) + 1;

			REP(i1, t) {
				int r1 = r - i1;
				int c1 = c + i1;
				int a1 = a[0][r1][c1];
				REP(i2, t) {
					int r2 = r - i2;
					int c2 = c + i2;
					int a2 = a[1][r2][c2];
					REP(i3, t) {
						int r3 = r - i3;
						int c3 = c + i3;
						int a3 = a[2][r3][c3];

						int h = calc(r1, r2, r3);
						if ((a1 < a2 && a2 < a3) || (a1 > a2 && a2 > a3)) {
							dp[1 - state][h] = 0;
							continue;
						}

						dp[1 - state][h] = 0;

						REP(d1, 2) {
							int nr1 = r1 + nexttttt[d1][0];
							int nc1 = c1 + nexttttt[d1][1];

							if (nr1 < 0 || nc1 < 0) continue;

							REP(d2, 2) {
								int nr2 = r2 + nexttttt[d2][0];
								int nc2 = c2 + nexttttt[d2][1];

								if (nr2 < 0 || nc2 < 0) continue;

								REP(d3, 2) {
									int nr3 = r3 + nexttttt[d3][0];
									int nc3 = c3 + nexttttt[d3][1];

									if (nr3 < 0 || nc3 < 0) continue;

									int hprev = calc(nr1, nr2, nr3);
									dp[1 - state][h] += dp[state][hprev];
									dp[1 - state][h] %= MOD;
								}
							}
						}
					}
				}
			}

			REP(i1, t) {
				int r1 = r - i1;
				REP(i2, t) {
					int r2 = r - i2;
					REP(i3, t) {
						int r3 = r - i3;
						int h = calc(r1, r2, r3);
						dp[state][h] = dp[1 - state][h];
					}
				}
			}

			state = 1 - state;
		}
		printf("%d\n", dp[state][calc(n - 1, n - 1, n - 1)]);
	}

	return 0;
}
