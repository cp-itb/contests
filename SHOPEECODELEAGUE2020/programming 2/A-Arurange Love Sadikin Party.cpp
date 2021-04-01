/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Arurange Love Sadikin Party
* Author  : Jehian Norman Saviero
* Problem : A - Highest Mountain
*/

/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>
 
// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std
 
Jehian Norman Saviero;
 
// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
 
// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")
 
// MACROS FOR ATTRIBUTE
#define fi first
#define se second
 
// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))
 
// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

#define valid(P) ((P) >= 0 && (P) < N)

int main() {
	int T;
	sci(T);
	int tc = 0;
	while (T--) {
		int N;
		sci(N);
		vi dat(N);
		bool visit[N+1];
		RESET(visit);
		queue<pi> q;
		for (int i = 0; i < N; ++i) {
			sci(dat[i]);
			if (dat[i] == 1) {
				q.push({dat[i], i});
			}
		}
		int ans = 0;
		int dat_ans[N+2];
		for (int i = 0; i <= N; ++i) {
			dat_ans[i] = INT_MAX;
		}
		while (!q.empty()) {
			int height, pos;
			tie(height, pos) = q.front();
			q.pop();
			if (!visit[pos]) {
				visit[pos] = 1;
				ans = max(ans, height);
				dat_ans[height] = min(dat_ans[height], pos);
				int nx = pos - 1;
				if (valid(nx) && !visit[nx] && dat[nx] == height+1) {
					q.push({dat[nx], nx});
				}
				nx = pos + 1;
				if (valid(nx) && !visit[nx] && dat[nx] == height+1) {
					q.push({dat[nx], nx});
				}
			}
		}
		printf("Case #%d: ", ++tc);
		if (ans == 0) {
			printf("%d %d\n", -1, -1);
		} else {
			printf("%d %d\n", ans, dat_ans[ans]);
		}
	}
	return 0;
}