/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : Arurange Code Party
 * Author  : Jehian Norman Saviero
 * Problem : H - Length Archiver
 */

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
	int curr = -1;
	int x;
	sci(x);
	curr = x;
	int cnt = 1;
	vector<pi> ans;
	while (sci(x) != EOF){
		if (x == curr){
			++cnt;
			if (cnt == 255){
				ans.pb({cnt, curr});
				cnt = 0;
			}
		} else {
			if (cnt) ans.pb({cnt, curr});
			curr = x;
			cnt = 1;
		}
	}
	if (cnt) ans.pb({cnt, curr});
	printf("%lld\n", 2LL*ans.size());
	string spasi = "";
	for (auto& it : ans){
		printf("%s%d %d", spasi.c_str(), it.fi, it.se);
		spasi = " ";
	}
	printf("\n");
	return 0;
}