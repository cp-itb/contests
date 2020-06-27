/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : Arurange Code Party
 * Author  : Jehian Norman Saviero
 * Problem : A - Biutiful Number
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

set<ll> ANS;
int main(){
	ll sum = 0;
	for (ll i = 1; i <= 10000; ++i){
		sum += i;
		ANS.insert(sum);
	}
	ll T;
	scll(T);
	for (ll tc = 1; tc <= T; ++tc){
		ll tmp;
		scll(tmp);
		printf("Case #%lld: %s\n", tc, ANS.find(tmp) != ANS.end() ? "YES" : "NO");
	}
	return 0;
}