/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : Arurange Code Party
 * Author  : Dewita Sonya Tarabunga
 * Problem : B - Raon and Ice Cream
 */

#include <bits/stdc++.h>

// MACROS SAMPAH
#define Arno using
#define Dewita namespace
#define Jehian std

Arno Dewita Jehian;

// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;

// MACROS FOR ATTRIBUTE
#define fi first
#define se second

// MACROS FOR FUNCTION AND METHOD
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define ALL(x) (x).begin(), (x).end()
#define ALLSIZE(x,n) (x), (x)+(n)
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))

// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

int main(){
	int N;
	int T;
	string S;
	sci(T);
	for (int tc = 1; tc <= T; ++tc){
		sci(N);
		cin >> S;
		vi FAC;
		for (int i = 1; SQR(i) <= N; ++i){
			if (N % i == 0) FAC.pb(i), FAC.pb(N / i);
		}
		int ans = 1;
		for (int x : FAC){
			int partition = N / x;
			int memo[2][26];
			RESET(memo);
			int res = x;
			for (int j = 0; j < partition; ++j){
				++memo[0][S[j]-'A'];
			}
			for (int i = partition; i < N; i += partition){
				RESET(memo[1]);
				for (int j = i; j < i + partition; ++j){
					++memo[1][S[j]-'A'];
				}
				for (int j = 0; j < 26; ++j){
					res = memo[0][j] != memo[1][j] ? 1 : res;
				}
			}
			ans = max(ans, res);
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}