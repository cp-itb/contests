/**
 * Contest : Ideafuse 2021 Final
 * Team    : Computer Saiyans
 * Author  : Jauhar Wibisono
 * Problem : I - Screening Test
 */


#include <bits/stdc++.h>
using namespace std;

void solve(){
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	int ans = 0;
	for (int i=m-1; i<n; i++){
		if (a[i] %= b.back()) ans++;
	}
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