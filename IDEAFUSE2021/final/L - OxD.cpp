/**
 * Contest : Ideafuse 2021 Final
 * Team    : Computer Saiyans
 * Author  : Jauhar Wibisono
 * Problem : L - Even Balls
 */

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	vector<int> dp(2, -1);
	dp[0] = 0;
	int ans = 0;
	for (int i=0; i<n; i++){
		vector<int> tmp = dp;
		for (int j=0; j<2; j++){
			if (dp[j] != -1) tmp[(j+a[i])%2] = max(tmp[(j+a[i])%2], dp[j] + a[i]);
		}
		dp = tmp;
	}
	cout << dp[0] << '\n';
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