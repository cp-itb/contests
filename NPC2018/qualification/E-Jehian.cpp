/**
 * Contest : NPC 2018 Qualification
 * Team    : Jehian Norman Saviero
 * Author  : Jehian Norman Saviero
 * Problem : E - Bermain Tanah
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

const ll sz = 4e5+5;
ll seg[2][sz], lazy[sz], a[sz];
ll N, M, X, L, R, Y, Z;

void check(ll p, ll s, ll e) {
	if (lazy[p] != 0) {
		seg[0][p] += lazy[p];
		seg[1][p] += lazy[p];
		if (s != e) {
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
		}
		lazy[p] = 0;
	}
}

void build(ll p, ll s, ll e) {
	check(p,s,e); 
	if (s == e) {
		seg[0][p] = a[s];
		seg[1][p] = a[s];
		return;
	}

	build(2*p,s,(s+e)/2);
	build(2*p+1,(s+e)/2+1,e);

	seg[0][p] = min(seg[0][2*p], seg[0][2*p+1]);
	seg[1][p] = max(seg[1][2*p], seg[1][2*p+1]);
}

void update(ll p, ll s, ll e, ll a, ll b, ll v) {
	check(p,s,e);
	if (s >= a && e <= b) {
		seg[0][p] += v;
		seg[1][p] += v;
		if (s != e) {
			lazy[2*p] += v;
			lazy[2*p+1] += v;
		}
		return;
	}
	if (s > b || e < a) {
		return;
	}
	update(2*p,s,(s+e)/2,a,b,v);
	update(2*p+1,(s+e)/2+1,e,a,b,v);
	seg[0][p] = min(seg[0][2*p], seg[0][2*p+1]);
	seg[1][p] = max(seg[1][2*p], seg[1][2*p+1]);
}

ll getMin(ll p, ll s, ll e, ll a, ll b) {
	check(p,s,e);

	if (s >= a && e <= b) {
		return seg[0][p];
	}
	
	if (s > b || e < a) {
		return INT_MAX;
	}

	return min(getMin(2*p,s,(s+e)/2,a,b),getMin(2*p+1,(s+e)/2+1,e,a,b));
}

ll getMax(ll p, ll s, ll e, ll a, ll b) {
	check(p,s,e);

	if (s >= a && e <= b) {
		return seg[1][p];
	}
	
	if (s > b || e < a) {
		return INT_MIN;
	}

	return max(getMax(2*p,s,(s+e)/2,a,b),getMax(2*p+1,(s+e)/2+1,e,a,b));
}
 
int main() {
	RESET(seg);
	scll(N);
	for (ll i = 0; i < N; i++) scll(a[i]);
	build(1,0,N-1);
	ll Q;
	scll(Q);
	while (Q--) {
		ll T;
		scll(T), scll(X), scll(Y);
		X--,Y--;
		if (T == 1) {
			scll(Z);
			update(1,0,N-1,X,Y,Z);
			continue;
		}
		printf("%lld\n", getMax(1,0,N-1,X,Y) - getMin(1,0,N-1,X,Y));
	}
	return 0;
}