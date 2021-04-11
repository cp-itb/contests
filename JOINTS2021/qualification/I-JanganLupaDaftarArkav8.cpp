 /**
  * Contest : Joints 2021 Qualification
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Jauhar Wibisono
  * Problem : I - Panahan
  */


#include <bits/stdc++.h>
using namespace std;

const int maxk = 13, maxn = 1004, maxm = 1003;
int n, m, k, p;
int a[maxk][maxk], s[maxn], t[maxm];
int dp[maxn][maxm];

void self_max(int &a, int b){
	a = max(a, b);
}

int main(){
	cin >> n >> m >> k >> p;
	for (int i=1; i<=k; i++){
		for (int j=1; j<=k; j++){
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=n; i++) cin >> s[i];
	for (int i=1; i<=m; i++) cin >> t[i];
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			dp[i][j] = -1e9;
		}
	}
	dp[0][0] = 0;
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			// skip target sekarang
			if (i < n) self_max(dp[i+1][j], dp[i][j]-p);
			// skip panah sekarang
			if (j < m) self_max(dp[i][j+1], dp[i][j]-p);
			// tembak panah sekarang
			if (i < n && j < m) self_max(dp[i+1][j+1], dp[i][j]+a[s[i+1]][t[j+1]]);
		}
	}
	cout << dp[n][m] << "\n";
}