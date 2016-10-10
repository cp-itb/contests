/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Ahmad Zaky
 * Problem : C - Beautiful Quadruple
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

int ntc, n, m, a[1111][1111], z[1111];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &m);
		FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
		ll ans = 0;
		FOR(l, 1, n - 1) {
			// bubbly sort
			FOR(i, 1, m) z[i] = i;
			FOR(i, 1, m - 1) {
				FORD(j, m, i + 1) {
					if (a[l][z[j]] < a[l][z[j - 1]]) {
						swap(z[j], z[j - 1]);
					}
				}
			}
			FOR(r, l + 1, n) {
				int p = 1;
				while (p <= m) {
					int cot = 0;
					int q = p;
					while (q <= m && a[l][z[q]] == a[l][z[p]]) {
						if (a[l][z[q]] == a[r][z[q]]) cot++;
						++q;
					}
					ans += cot * (cot - 1) / 2;
					p = q;
				}
			}
		}
		printf("Case #%d: %lld\n", itc, ans);
	}
	
	return 0;
}