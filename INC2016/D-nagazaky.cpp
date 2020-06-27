/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Ahmad Zaky
 * Problem : D - Arithmetic Sequence
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

#define MAX 0
#define MIN 1
#define INF 2000000000

struct RMQ {
	vector<int> a;
	int n, com;

	RMQ (int n, int com) {
		this->com = com;
		this->n = 1;
		while (this->n < n) this->n <<= 1;
		a.resize((this->n + 1) << 2);
	}

	void update(int p, int value) {
		update(1, 1, n, p, value);
	}

	void update(int v, int l, int r, int p, int value) {
		if (l == r && l == p) {
			a[v] = value;
		} else if (l <= p && p <= r) {
			int vl = v << 1;
			int vr = vl | 1;
			int m = (l + r) / 2;
			update(vl, l, m, p, value);
			update(vr, m + 1, r, p, value);
			switch (com) {
				case MAX: a[v] = max(a[vl], a[vr]);
				break;

				case MIN: a[v] = min(a[vl], a[vr]);
				break;
			}
		}
	}

	int query(int l, int r) {
		return query(1, 1, n, l, r);
	}

	int query(int v, int l, int r, int p, int q) {
		if (p <= l && r <= q) {
			return a[v];
		} else if (q < l || r < p) {
			switch (com) {
				case MAX: return -INF;
				case MIN: return INF;
			}
		} else {
			int vl = v << 1;
			int vr = vl | 1;
			int m = (l + r) / 2;
			int ansl = query(vl, l, m, p, q);
			int ansr = query(vr, m + 1, r, p, q);
			switch (com) {
				case MAX: return max(ansl, ansr);
				case MIN: return min(ansl, ansr);
			}
		}
	}
};

#define MAXN 100100
int ntc, n, nq, a[MAXN], d[MAXN];
int qt, p, q;

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &nq);
		FOR(i, 1, n) scanf("%d", &a[i]);

		n--;
		RMQ rmqmin(n, MIN), rmqmax(n, MAX);
		FOR(i, 1, n) {
			d[i] = a[i + 1] - a[i];
			rmqmin.update(i, d[i]);
			rmqmax.update(i, d[i]);
		}

		printf("Case #%d:\n", itc);
		FOR(iq, 1, nq) {
			scanf("%d%d%d", &qt, &p, &q);
			if (qt == 1) {
				a[p] = q;
				if (p > 1) {
					d[p - 1] = a[p] - a[p - 1];
					rmqmin.update(p - 1, d[p - 1]);
					rmqmax.update(p - 1, d[p - 1]);
				}
				if (p <= n) {
					d[p] = a[p + 1] - a[p];
					rmqmin.update(p, d[p]);
					rmqmax.update(p, d[p]);
				}
			} else {
				int mindiff = rmqmin.query(p, q - 1);
				int maxdiff = rmqmax.query(p, q - 1);
				if (p == q || mindiff == maxdiff) {
					puts("YES");
				} else {
					puts("NO");
				}
			}
		}
	}
	
	return 0;
}