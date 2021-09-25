/**
 * Contest : NPC Schemastics 2021
 * Team    : Ayam Bangkok Putih cs.
 * Author  : Jauhar Wibisono
 * Problem : F - Fun Quiz
 */

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7; 

long long mod_pow(long long a, long long b){
	long long ret = 1;
	for (; b; b>>=1){
		if (b&1) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}

long long mod_inv(long long a){
	return mod_pow(a, mod-2);
}

const long long inv2 = mod_inv(2);

long long tri(long long a){
	return a * (a+1) % mod * inv2 % mod;
}

long long n, s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	n %= mod;
	s %= mod;
	cout << (tri(s*n % mod) - tri((n-1+mod) % mod) + mod) % mod << '\n';
	return 0;
}