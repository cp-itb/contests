/**
 * Contest : NPC 2018 Qualification
 * Team    : Jehian Norman Saviero
 * Author  : Jehian Norman Saviero
 * Problem : B - Lonely Tutut
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
typedef double ld;
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

const int sz = 1e8+5;
bool isFibo[sz];

void PreCompute() {
	isFibo[1] = isFibo[2] = 1;
	int A = 1;
	int B = 2;
	int C;
	while (A + B < sz) {
		C = A + B;
		isFibo[C] = 1;
		A = B;
		B = C;
	}
}

const ll MD = 1e9+7;

ll powMod(ll a, ll p) {
	ll res = 1;
	for (; p; p >>= 1, a = SQR(a)%MD) {
		if (p & 1) {
			res *= a;
			res %= MD;
		}
	}
	return res;
}

int main() {
	PreCompute();
	ll T;
	scll(T);
	while (T--) {
		ll N;
		scll(N);
		if (N > 10 && isFibo[N]) {
			puts("YEY");
		} else {
			ll a = 2LL;
			ll b = powMod(2,N);
			--b;
			b += MD;
			b %= MD;
			ll c = (a * b) % MD;
			c += 4;
			c %= MD;
			printf("%lld\n", c);
		}
	}
	return 0;
}