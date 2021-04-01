/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Arurange Love Sadikin Party
* Author  : Dewita Sonya Tarabunga
* Problem : B - Judging Servers
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
	ll t,s,n;
	ll p[1010];
	ll dp[1010][1010][2]={};
	ll INF = 2e9;
	scanf("%lld", &t);
	for (ll T=1;T<=t;++T) {
		scanf("%lld %lld", &s, &n);
		for (ll i=1;i<=s;++i) {
			scanf("%lld", p+i);
		}
		if (s==1) {
			printf("Case %lld: %lld\n", T, p[1]);
			continue;
		}
		for (ll i=0;i<=s;++i) {
			dp[i][0][0] = dp[i][0][1] = 0;
			for (ll j=1;j<=s;++j) {
				dp[i][j][0] = dp[i][j][1] = INF;
			}
		}
		dp[1][1][1] = p[1];
		for (ll i=2;i<=s;++i) {
			dp[i][1][1] = p[i];
			dp[i][1][0] = min(dp[i-1][1][0], dp[i-1][1][1]);
			for (ll j=2;j<=i;++j) {
				dp[i][j][1] = p[i]+min(min(dp[i-2][j-2][0], dp[i-2][j-2][1]), dp[i-1][j-1][1]);
				dp[i][j][0] = p[i-1]+min(dp[i-2][j-2][0], dp[i-2][j-2][1]);
				if (i-1>=j) {
					dp[i][j][0] = min(dp[i][j][0], min(dp[i-1][j][0], dp[i-1][j][1]));
				}
			}
		}
		printf("Case %lld: %lld\n", T, min(dp[s][n][0], dp[s][n][1]));
	}
	return 0;
}