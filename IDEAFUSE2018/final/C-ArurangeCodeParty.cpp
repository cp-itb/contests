/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : Arurange Code Party
 * Author  : Jehian Norman Saviero
 * Problem : C - Copy Duck
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
const ll MD = 1e9+7;
ll POW(ll A, ll B){
	ll res = 1;
	for (; B; B >>= 1, A = SQR(A)){
		if (B & 1) res *= A;
	}
	return res;
}

ll POWMOD(ll A, ll B){
	ll res = 1;
	for (; B; B >>= 1, A = SQR(A)%MD){
		if (B & 1) res = (res*A)%MD;
	}
	return res;
}

vll RANKVAL;

void preCompute(){
	RANKVAL.pb(1);
	while (RANKVAL.size() < 63) RANKVAL.pb(RANKVAL.back() * 2LL);
}

int getRANKVAL(ll val){
	int idx = lower_bound(ALL(RANKVAL), val) - RANKVAL.begin();
	return lower_bound(ALL(RANKVAL), val) - RANKVAL.begin() - (RANKVAL[idx] != val);
}

int main(){
	preCompute();
	ll T;
	scll(T);
	for (ll tc = 1; tc <= T; ++tc){
		ll N, K;
		scll(N);
		scll(K);
		ll tmp;
		bool anyZero = 0;
		ll RANKVALMAX = 0;
		priority_queue<ll, vll, greater<ll> > pq;
		for (ll i = 0; i < N; ++i){
			scll(tmp);
			anyZero = anyZero || tmp == 0;
			RANKVALMAX = max(RANKVALMAX, (ll) getRANKVAL(tmp));
			pq.push(tmp);
		}
		ll ans = 0;
		if (anyZero){
			while (!pq.empty()){
				ans += pq.top();
				pq.pop();
				ans %= MD;
			}
		} else {
			while (K > 0 && getRANKVAL(pq.top()) != RANKVALMAX){
				--K;
				pq.push(pq.top() * 2LL);
				pq.pop();
			}
			ll sisa = K % N;
			ll tiap = K / N;
			while (sisa > 0){
				ll curr = pq.top();
				pq.pop();
				curr *= 2;
				curr %= MD;
				curr *= POWMOD(2, tiap);
				curr %= MD;
				ans += curr;
				ans %= MD;
				--sisa;
			}
			while (!pq.empty()){
				ll curr = pq.top();
				pq.pop();
				curr *= POWMOD(2, tiap);
				curr %= MD;
				ans += curr;
				ans %= MD;
			}
		}
		printf("Case #%lld: %lld\n", tc, ans);
	}
	return 0;
}