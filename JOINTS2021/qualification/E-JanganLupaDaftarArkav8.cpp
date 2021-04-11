 /**
  * Contest : Joints 2021 Qualification
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Jauhar Wibisono
  * Problem : E - Kuda
  */

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
const int maxt = 100, maxn = 303, maxm = 303, num_of_moves = 4;
const int dr[] = {1, 2, 2, 1}, dc[] = {-2, -1, 1, 2};
long long ways[maxn][maxm];
int t;

bool valid(int r, int c){
	return (r > 0 && c > 0 && r < maxn && c < maxm);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		memset(ways, 0, sizeof ways);
		for (int cc=1; cc<=m; cc++) ways[1][cc] = 1;
		for (int r=1; r<=n; r++){
			for (int cc=1; cc<=m; cc++){
				for (int i=0; i<num_of_moves; i++){
					int nextr = r+dr[i], nextc = cc+dc[i];
					if (valid(nextr, nextc)){
						ways[nextr][nextc] += ways[r][cc];
						ways[nextr][nextc] %= mod;
					}
				}
			}
		}
		long long ans = 0;
		for (int c=1; c<=m; c++){
			ans += ways[n][c];
			ans %= mod;
		}
		cout << ans << "\n";
	}
}