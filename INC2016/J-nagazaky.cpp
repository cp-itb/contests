/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Ahmad Zaky
 * Problem : J - Rational Number
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

int ntc, a, b;

ll modpow(ll a, ll b, ll mod) {
	if (b == 0) {
		return 1;
	} else {
		ll temp = modpow((a * a) % mod, b / 2, mod);
		if (b & 1) temp = (temp * a) % mod;
		return temp;
	}
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &a, &b);
		a = abs(a); b = abs(b);
		if (a == 0) {
			printf("Case #%d: %d\n", itc, 0);
			continue;
		}
		int d = __gcd(b, a);
		a /= d; b /= d;
		while (b % 2 == 0) {
			b /= 2;
		}
		while (b % 5 == 0) {
			b /= 5;
		}
		if (b == 1) {
			printf("Case #%d: %d\n", itc, 0);
			continue;
		}

		// factorize b
		int temp = b;
		vector<pii> p;
		for (int i = 2; i * i <= b; ++i) {
			if (temp % i) continue;
			int k = 0;
			while (temp % i == 0) {
				++k;
				temp /= i;
			}
			p.PB(MP(i, k));
		}
		if (temp > 1) {
			p.PB(MP(temp, 1));
		}
		// calculate phi
		int phi = 1;
		FORIT(it, p) {
			phi *= it->A - 1;
			REP(i, it->B - 1) phi *= it->A;
		}

		// factorize phi
		vector<int> factors;
		for (int i = 1; i * i <= phi; ++i) {
			if (phi % i) continue;
			factors.PB(i);
			if (i * i != phi) {
				factors.PB(phi / i);
			}
		}
		sort(ALL(factors));

		int ans = -1;
		FORIT(it, factors) {
			if (modpow(10, *it, b) == 1) {
				ans = *it;
				break;
			}
		}

		printf("Case #%d: %d\n", itc, ans);
	}
	
	return 0;
}