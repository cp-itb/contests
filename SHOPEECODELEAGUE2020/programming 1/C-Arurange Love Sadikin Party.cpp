/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Arurange Love Sadikin Party
* Author  : Dewita Sonya Tarabunga
* Problem : C - Sequence
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
	ll n,m,k;
	ll MOD = 1e9+7;
	ll md[5010][2010];
	ll a,b,c,dp[2010];
	ll cnt[2010]={};
	scanf("%lld %lld %lld", &n, &m, &k);
	for (ll i=1;i<=n;++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		for (ll j=1;j<=k;++j) {
			dp[j] = (a*j*j+b)%k;
		}
		ll r,s;
		r = c/k;
		s = c-k*r;
		for (ll j=1;j<=k;++j) {
			cnt[dp[j]] += r;
		}
		for (ll j=1;j<=s;++j) {
			cnt[dp[j]]++;
		}
	}
	ll ans[2010]={},tmp[2010];
	ans[0] = 1;
	while (m) {
		if (m&1LL) {
			for (ll i=0;i<k;++i) {
				tmp[i] = 0;
			}
			for (ll i=0;i<k;++i) {
				for (ll j=0;j<k;++j) {
					tmp[(i+j)%k] += (ans[i]*cnt[j])%MOD;
					tmp[(i+j)%k] %= MOD;
				}
			}
			for (ll i=0;i<k;++i) {
				ans[i] = tmp[i];
			}
		}
		for (ll i=0;i<k;++i) {
			tmp[i] = 0;
		}
		for (ll i=0;i<k;++i) {
			for (ll j=0;j<k;++j) {
				tmp[(i+j)%k] += (cnt[i]*cnt[j])%MOD;
				tmp[(i+j)%k] %= MOD;
			}
		}
		for (ll i=0;i<k;++i) {
			cnt[i] = tmp[i];
		}
		m >>= 1LL;
	}
	printf("%lld\n", ans[0]);
	return 0;
}