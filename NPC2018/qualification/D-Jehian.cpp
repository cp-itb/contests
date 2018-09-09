/**
 * Contest : NPC 2018 Qualification
 * Team    : Jehian Norman Saviero
 * Author  : Jehian Norman Saviero
 * Problem : D - Siapa Pasanganku
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

int main() {
	string s;
	getline(cin, s);
	vll dat;
	stringstream ss(s);
	ll tmp;
	map<ll, int> cnt;
	while (ss >> tmp) {
		dat.pb(tmp);
		++cnt[tmp];
	}
	ll N;
	scll(N);
	for (auto& itt : cnt) {
		int it, num;
		tie(it,num) = itt;
		ll curr = N-it;
		if (curr != it && cnt.find(curr) != cnt.end()) {
			puts("ADA");
			return 0;
		} else if (curr == it && num > 1) {
			puts("ADA");
			return 0;
		}
	}
	puts("TIDAK ADA");
	return 0;
}