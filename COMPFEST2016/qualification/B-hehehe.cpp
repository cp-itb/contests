/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : hehehe
 * Author  : Ahmad Zaky
 * Problem : B - Baskom Mania
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

int n;
ll m, k, a[MAXN], w[MAXN], desc;

bool boom(ll x) {
	ll d = (x - 1) * desc;
	FOR(i, 1, n) {
		if (w[i] - d <= 0) {
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%lld%d%lld", &m, &n, &k);
		FOR(i, 1, n) {
			scanf("%lld", &a[i]);
		}

		// kalo kayak gini ac jelek banget soalnya
		if (m == 0) {
			puts("0");
			continue;
		}

		w[0] = m;
		bool found = false;
		ll ans;
		FOR(i, 1, n) {
			w[i] = w[i - 1] + k;
			w[i] -= a[i];
			if (w[i] == 0) {
				ans = i;
				found = true;
				break;
			} else if (w[i] < 0) {
				ans = i - 1;
				found = true;
				break;
			}
		}

		if (found) {
			printf("%lld\n", ans);
			continue;
		}

		if (w[n] >= w[0]) {
			puts("-1");
			continue;
		}

		desc = w[0] - w[n];
		ll l = 1, r = m + m;
		assert(boom(m + 1));
		while (l < r) {
			// printf("[%lld..%lld]\n", l, r);
			ll x = (l + r + 1) / 2LL;
			// use full x, after that boom
			if (boom(x)) {
				r = x - 1;
			} else {
				l = x;
			}
		}
		// printf("l = %lld\n", l);
		assert(l == r);
		assert(!boom(l));
		assert(boom(l + 1));
		ll d = l * desc;
		FOR(i, 1, n) {
			if (w[i] - d == 0) {
				ans = l * n + i;
				found = true;
				break;
			} else if (w[i] - d < 0) {
				ans = l * n + i - 1;
				found = true;
				break;
			}
		}
		assert(found);
		printf("%lld\n", ans);
	}

	return 0;
}
