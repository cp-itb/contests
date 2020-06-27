/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : I See the One
 * Author  : Tony
 * Problem : F - Ocarth
 */
#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll to10(ll val){
	ll res = 0;
	ll mul = 1;
	while(val){
		res += mul*(val%10);
		val /=10;
		mul *= 8;
	}
	return res;
}

ll to8(ll val){
	return val>0? 10*to8(val/8)+val%8 : 0;
}

ll n;
ll a[13];

int main(){
	ll tmp = 1;
	a[0] = 1;
	for(int i=1;i<13;++i){
		a[i] = a[i-1] + i*7*tmp;
		tmp *= 8;
	}
	int tc;
	scanf("%d", &tc);
	tc = to10(tc);
	for(int cc=1;cc<=tc;cc++){
		printf("Case #%d: ", (int) to8(cc));
		scanf("%lld", &n);
		n = to10(n);
		ll ans = 0;
		int offset = 0;
		int ub = upper_bound(a, a+13, n) - a - 1;
		n -= a[ub];
		ans += pow(8, ub);
		offset = n%(ub+1);
		n /= ub+1;
		ans += n;
		stack<int> s;
		do{
			s.push(ans%8);
			ans /= 8;
		}while(ans);
		for(int i=0;!s.empty();++i){
			if(i==offset)
				printf("(%d)", s.top());
			else
				printf("%d", s.top());
			s.pop();
		}
		printf("\n");
	}
	return 0;
}