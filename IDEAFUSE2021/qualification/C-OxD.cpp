/**
 * Contest : Ideafuse 2021 Qualification
 * Team    : OxD
 * Author  : Jauhar Wibisono
 * Problem : C - Faster Computation
 */
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int mod_mul(int a, int b){
	return 1LL * a * b % mod;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1), b(n+1);
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	vector<int> pref(n+1);
	pref[0] = 0;
	for (int i=1; i<=n; i++) pref[i] = (pref[i-1] + mod_mul(a[i], b[i])) % mod;
	int ans = 0;
	for (int i=1; i<=n; i++) ans = (ans + mod_mul(mod_mul(a[i], b[i]), pref[n])) % mod;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	for (int tc=1; tc<=tcs; tc++){
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}