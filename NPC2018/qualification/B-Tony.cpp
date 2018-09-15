/**
 * Contest : NPC 2018 Qualification
 * Team    : Tony
 * Author  : Tony
 * Problem : B - Lonely Tutut
 */
 
 #include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
ll fib[300];
int len;

ll powd(ll val, ll exp){
	ll ans = 1;
	for(;exp;val = val*val%mod){
		if(exp&1){
			ans *= val;
			ans %= mod;
		}
		exp >>= 1;
	}
	return ans;
}

int main(){
	fib[0] = 0;
	fib[1] = 1;
	for(i=2;;++i){
		fib[i] = fib[i-1]+fib[i-2];
		if(fib[i] > 1e8)
			break;
	}
	len = i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n>10 && *lower_bound(fib, fib+len, n) == n)
			puts("YEY");
		else
			printf("%lld\n", (mod + 3 + powd(2, n+1)-1) % mod);
	}
	return 0;
}