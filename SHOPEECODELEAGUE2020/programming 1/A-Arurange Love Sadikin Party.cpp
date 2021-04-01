/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Arurange Love Sadikin Party
* Author  : Jehian Norman Saviero
* Problem : A - Search Engine
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
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
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
 
int main() {
	int T;
	sci(T);
	int tc = 1;
	while (T--) {
		int N, Q;
		sci(N), sci(Q);
		map<vector<string>, int> cnt;
		string tmp;
		getline(cin, tmp);
		for (int i = 0; i < N; ++i ) {
			getline(cin, tmp);
			stringstream ss(tmp);
			vector<string> dat;
			while (ss >> tmp) {
				dat.pb(tmp);
			}
			map<vector<string>, int> curr;
			for (int i = 0; i < dat.size(); ++i) {
				vector<string> proc;
				for (int j = i; j < dat.size(); ++j) {
					proc.pb(dat[j]);
					curr[proc] = 1;
				}
			}
			for (auto &it : curr) {
				cnt[it.fi] += it.se;
			}
		}
		printf("Case %d:\n", tc++);
		while (Q--) {
			getline(cin, tmp);
			vector<string> separator;
			stringstream ss(tmp);
			while (ss >> tmp) {
				separator.pb(tmp);
			}
			printf("%d\n", cnt[separator]);
		}
	}
	return 0;
}