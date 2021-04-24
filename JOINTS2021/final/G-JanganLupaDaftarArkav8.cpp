 /**
  * Contest : Joints 2021 Final
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Jauhar Wibisono
  * Problem : G - Rumah Sakit Darurat
  */

#include <bits/stdc++.h>
using namespace std;

const int maxnm = 1002;
int n, m;
long long p[maxnm][maxnm];

long long solve(int a, int b){
	if (a > n || b > m) return 3e18;

	vector<vector<long long>> col_min(n, vector<long long>(m, 0));
	for (int j=0; j<m; j++){
		deque<pair<int, long long>> dq;
		for (int i=0; i<n; i++){
			while (!dq.empty() && dq.front().first <= i-a) dq.pop_front();
			while (!dq.empty() && dq.back().second >= p[i][j]) dq.pop_back();
			dq.push_back({i, p[i][j]});
			if (i >= a-1) col_min[i][j] = dq.front().second;
		}
	}

	vector<vector<long long>> row_min(n, vector<long long>(m, 0));
	for (int i=a-1; i<n; i++){
		deque<pair<int, long long>> dq;
		for (int j=0; j<m; j++){
			while (!dq.empty() && dq.front().first <= j-b) dq.pop_front();
			while (!dq.empty() && dq.back().second >= col_min[i][j]) dq.pop_back();
			dq.push_back({j, col_min[i][j]});
			if (j >= b-1) row_min[i][j] = dq.front().second;
		}
	}

	vector<vector<long long>> pref(n+1, vector<long long>(m+1, 0));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + p[i-1][j-1];
		}
	}

	vector<vector<long long>> sqr_pref(n+1, vector<long long>(m+1, 0));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			sqr_pref[i][j] = sqr_pref[i-1][j] + sqr_pref[i][j-1] - sqr_pref[i-1][j-1] + (p[i-1][j-1]*p[i-1][j-1]);
		}
	}

	long long ret = 3e18;
	for (int i=a-1; i<n; i++){
		for (int j=b-1; j<m; j++){
			long long sum = pref[i+1][j+1] - pref[i-a+1][j+1] - pref[i+1][j-b+1] + pref[i-a+1][j-b+1]; 
			long long sqr_sum = sqr_pref[i+1][j+1] - sqr_pref[i-a+1][j+1] - sqr_pref[i+1][j-b+1] + sqr_pref[i-a+1][j-b+1];
			long long mn = row_min[i][j];
			long long candidate = sqr_sum - 2*sum*mn + a*b*mn*mn;
			ret = min(ret, candidate);
		}
	}
	return ret;
}

int main(){
	int a, b;
	cin >> n >> m >> a >> b;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> p[i][j];
		}
	}
	long long ans = solve(a, b);
	ans = min(ans, solve(b, a));
	cout << ans << "\n";
}
