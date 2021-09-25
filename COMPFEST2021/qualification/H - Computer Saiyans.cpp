/**
 * Contest : Compfest 13 Qualification
 * Team    : Computer Saiyans
 * Author  : Kinantan Arya Bagaspati
 * Problem : Hitung Sigma
 */

#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long pangkat(long long a, long long b){
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}

long long fac[200069];
void init(){
    fac[0] = 1;
    for(int i=1; i<200069; i++){
        fac[i] = fac[i-1]*i%mod;
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    long long t, n, m, k, ans=0;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        ans += fac[n+m]*inv(fac[k])%mod*inv(fac[n+m-k])%mod;
    }
    cout << ans % mod << endl;
	return 0;
}
