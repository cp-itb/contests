/**
 * Contest : Compfest 13 Qualification
 * Team    : Computer Saiyans
 * Author  : Jauhar Wibisono
 * Problem : Lingkaran Cantik
 */

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long n, m;

long long mod_pow(long long a, long long b){
	long long ret = 1;
	a %= mod;
	for (; b; b>>=1){
		if (b&1) ret = ret * a % mod;
		a = a * a % mod;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	if (n == 1){
		cout << m%mod << '\n';
		return 0;
	}
	long long ans = mod_pow(m-1, n);
	if (n&1) ans -= m-1;
	else ans += m-1;
	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << '\n';
	return 0;
}