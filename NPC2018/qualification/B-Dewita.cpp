/**
 * Contest : NPC 2018 Qualification
 * Team    : Dewita Sonya
 * Author  : Dewita Sonya
 * Problem : B - Lonely Tutut
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<ll, bool> m;
ll n,t,INF=1e8,MOD=1e9+7,ans;
ll x, y, z;

ll fastpow(ll a, ll b) {
    if (b==0) return 1;
    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y) % MOD;
        }
        y = (y*y) % MOD;
        b /= 2;
    }
    return x;
}

int main() {
    x = y = 1;
    z = 2;
    while (z<=INF) {
        if (z>10) m[z] = 1;
        x = y;
        y = z;
        z = x+y;
    }
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        if (m[n]) puts("YEY");
        else {
            ans = (fastpow(2, n) + MOD - 1) % MOD;
            ans = (ans*2+4)%MOD;
            printf("%lld\n", ans);
        }
    }
    return 0;
}