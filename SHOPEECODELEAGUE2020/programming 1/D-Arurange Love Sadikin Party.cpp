/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Arurange Love Sadikin Party
* Author  : Dewita Sonya Tarabunga
* Problem : D - Item Stock
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll n;
ll p[100010],q[100010],s[100010],fp[100010],rq[100010];
vector<ll> v[100010];
bool f[100010];
 
void dfs(ll x, ll p) {
	if (!f[x]) {
		s[x] = s[p]/rq[x];
	}
	for (ll e:v[x]) {
		dfs(e, x);
	}
}
 
int main() {
	scanf("%lld %lld", &n, s+1);
	p[1] = fp[1] = 0;
	f[1] = 1;
	for (ll i=2;i<=n;++i) {
		ll t,pp,qq,ss;
		scanf("%lld %lld %lld", &t, &pp, &qq);
		v[pp].push_back(i);
		p[i] = pp;
		rq[i] = qq;
		if (t==1) {
			if (f[pp]) {
				fp[i] = pp;
				q[i] = qq;
			} else {
				fp[i] = fp[pp];
				q[i] = qq*q[pp];
			}
			f[i] = 0;
		} else {
			scanf("%lld", &ss);
			if (f[pp]) {
				fp[i] = pp;
				s[pp] -= ss*qq;
			} else {
				fp[i] = fp[pp];
				s[fp[i]] -= ss*qq*q[pp];
			}
			s[i] = ss;
			q[i] = qq;
			f[i] = 1;
		}
	}
	dfs(1, 0);
	for (ll i=1;i<=n;++i) {
		printf("%lld\n", s[i]);
	}
	return 0;
}