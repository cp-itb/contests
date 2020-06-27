/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : hehehe
 * Author  : Ahmad Zaky
 * Problem : B - Kode Keras
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

#define MAXN 50500
#define MAXT 86400

int ntc, n, ans[MAXN], t[MAXT + 5], s[MAXN], e[MAXN];
pair<pii, int> a[MAXN];

char dummy1[111], dummy2[111];

int decode(const char* c) {
	int h, m, s;
	assert(sscanf(c, "%d:%d:%d", &h, &m, &s) == 3);
	return 3600 * h + 60 * m + s;
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		RESET(t, 0);
		scanf("%d", &n);
		REP(i, n) {
			scanf("%s %s", dummy1, dummy2);
			s[i] = decode(dummy1), e[i] = decode(dummy2);
			a[i] = MP(MP(s[i], -e[i]), i);
			t[s[i]]++; t[e[i]]--;
		}
		FOR(i, 1, MAXT) {
			t[i] += t[i - 1];
		}
		sort(a, a + n);
		vector<pair<pii, int> > v;
		vector<int> idxv;
		set<int> markfordeletion;
		v.push_back(a[0]);
		for (int i = 1; i < n; ++i) {
			pair<pii, int> last = v.back();
			if (a[i].A.A > last.A.A && -a[i].A.B > -last.A.B) {
				v.push_back(a[i]);
			} else if (a[i].A.A == last.A.A && a[i].A.B == last.A.B) {
				markfordeletion.insert(SZ(v) - 1);
			}
		}
		RESET(ans, -1);
		multiset<int> ts;
		int startt = 0, lastt = 0;
		REP(i, SZ(v)) {
			if (EXIST(i, markfordeletion)) {
				continue;
			}
			// printf("[%d..%d]\n", v[i].A.A, -v[i].A.B);
			fflush(stdout);
			while (lastt < -v[i].A.B) {
				// printf("inserting t = %d: %d\n", lastt, t[lastt]);
				// fflush(stdout);
				ts.insert(t[lastt++]);
			}
			while (startt < v[i].A.A) {
				multiset<int>::iterator it = ts.find(t[startt++]);
				// printf("attempting to erase t = %d: %d\n", startt - 1, t[startt - 1]);
				assert(it != ts.end());
				ts.erase(it);
			}
			int mint = (*(ts.begin()));
			if (mint == 1) {
				ans[v[i].B] = 1;
			} else {
				ans[v[i].B] = 2;
			}
		}
		REP(i, n) {
			printf("%d\n", ans[i]);
			// fflush(stdout);
		}
	}

	return 0;
}
