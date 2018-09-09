/**
 * Contest : NPC 2018 Qualification
 * Team    : Dewita Sonya
 * Author  : Dewita Sonya
 * Problem : A - Dadu Joris
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t,m,n;
ll a[10],INF=1e13,MAXN=1e6;
long double ans,tmp,dp[10][1000010]={},dv;

int main() {
    for (ll i=1;i<=8;++i) {
        for (ll j=0;j<=MAXN;++j) {
            dp[i][j] = (double(i)+sqrt(i*i+4*j))/2.;
            dp[i][j] += dp[i][j-1];
        }
    }
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &m, &n);
        for (ll i=0;i<m;++i) {
            scanf("%lld", a+i);
        }
        ans = 0;
        dv = (long double)1/(n*m);
        for (ll i=0;i<m;++i) {
            tmp = dp[a[i]][n-1];
            tmp *= dv;
            ans += tmp;
        }
        printf("%.4Lf\n", ans);
    }
    return 0;
}