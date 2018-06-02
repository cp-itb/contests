/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : Arurange Code Party
 * Author  : Dewita Sonya Tarabunga, Jehian Norman Saviero
 * Problem : F - Ocarth
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

ll toDec(string A){
	ll res = 0;
	for (auto& it : A){
		res *= 8;
		res += it - 48;
	}
	return res;
}

string toString(ll A){
	string res = "";
	if (A == 0) return "0";
	else  {
		while (A){
			res.pb(A % 10 + '0');
			A /= 10;
		}
		return res;
	}
}

ll toInt(string A){
	ll res = 0;
	for (auto& it : A){
		res *= 10;
		res += it - 48;
	}
	return res;
}

string toOct(ll A){
	string res = "";
	while (A){
		res.pb(A % 8 + '0');
		A /= 8;
	}
	reverse(ALL(res));
	return res;
}

string toOct(string A){
	return toOct(toInt(A));
}

vll pref;

void PreCompute(){
	pref.pb(0);
	ll curr = 8;
	for (ll i = 1; i <= 18; ++i){
		pref.pb(pref.back() + i * (curr - curr / 8LL) );
		curr *= 8LL;
	}
}

ll POW(ll A, ll B){
	ll res = 1;
	for (; B; B >>= 1, A = SQR(A)){
		if (B & 1) res *= A;
	}
	return res;
}

int main(){
	PreCompute();
	string A;
	cin >> A;
	int T = toDec(A);
	for (int tc = 1; tc <= T; ++tc){
		cin >> A;
		ll N = toDec(A);
		printf("Case #%s: ", toOct((ll) tc).c_str());
		--N;
		ll banyak_digit = lower_bound(ALL(pref), N) - pref.begin();
		ll bef = banyak_digit;
		bef -= pref[banyak_digit] > N;
		banyak_digit += pref[banyak_digit] == N;
		N -= pref[bef];
		ll sisa = N % banyak_digit;
		ll urutan = N / banyak_digit;
		string ans = toOct(urutan + POW(8, banyak_digit-1));
		for (int i = 0; i < ans.size(); ++i){
			if (i == sisa){
				printf("(%c)", ans[i]);
			} else {
				printf("%c", ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}