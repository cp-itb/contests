/**
 * Contest : NPC Schemastics 2021
 * Team    : Ayam Bangkok Putih cs.
 * Author  : Jauhar Wibisono
 * Problem : G - Gabung Kata
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+4;
const long long mod[] = {1000000007, 1000000009}, base = 101;
string s[2];
int n[2];
long long hsh[2][2][maxn];

long long mod_pow(long long a, long long b, long long m){
	long long ret = 1;
	for (; b; b>>=1){
		if (b&1) ret = (ret * a) % m;
		a = (a * a) % m;
	}
	return ret;
}

bool cek(int l1, int r1, int l2, int r2){
	// cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
	bool ret = true;
	for (int i=0; i<2; i++){
		long long v1 = ((hsh[i][0][r1] - hsh[i][0][l1]) % mod[i] + mod[i]) % mod[i];
		long long v2 = ((hsh[i][1][r2] - hsh[i][1][l2]) % mod[i] + mod[i]) % mod[i];
		v1 *= mod_pow(base, l2+1, mod[i]);
		v1 %= mod[i];
		v2 *= mod_pow(base, l1+1, mod[i]);
		v2 %= mod[i];
		if (v1 != v2) ret = false;
	}
	// cout << ret << '\n';
	return ret;
}

// void tes(){
// 	while (1){
// 		int l, r;
// 		cin >> l >> r;
// 		cout << 
// 	}
// }

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s[0] >> s[1];
	if (s[0].length() > s[1].length()) swap(s[0], s[1]);
	n[0] = s[0].length();
	n[1] = s[1].length();
	// bikin hsh
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			hsh[i][j][0] = 0;
			for (int k=1; k<=n[j]; k++){
				hsh[i][j][k] = (hsh[i][j][k-1] + mod_pow(base, k, mod[i]) * s[j][k-1] % mod[i]) % mod[i];
			}
		}
	}
	// tes();
	// cek s substring t atau bukan
	bool ok = false;
	for (int i=n[0]; i<=n[1]; i++){
		if (cek(0, n[0], i-n[0], i)) ok = true;
	}
	if (ok){
		cout << n[1] << '\n';
		return 0;
	}
	// pasangin prefix - suffix
	int ans = n[0] + n[1];
	// int l = 1, r = n[0];
	for (int i=1; i<=n[0]; i++){
		// if (cek(0, mid, n[1]-mid, n[1])) cout << 1 << ' ' << mid << ' ' << n[1]-mid+1 << ' ' << n[1] << '\n';
		// if (cek(n[0]-mid, n[0], 0, mid)) cout << n[0]-mid+1 << ' ' << n[0] << ' ' << 1 << ' ' << mid << '\n';
		if (cek(0, i, n[1]-i, n[1]) || cek(n[0]-i, n[0], 0, i)){
			ans = n[0] + n[1] - i;
		}
	}
	cout << ans << '\n';
	return 0;
}