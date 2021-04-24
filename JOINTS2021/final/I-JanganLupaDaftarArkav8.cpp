/**
  * Contest : Joints 2021 Final
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Jauhar Wibisono
  * Problem : I - Vaksin
  */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1002, maxvacc = 11;
int n, e, m, s;
vector<int> vacc_nodes;
int adjm[maxn][maxn], dist[maxn][maxn];
int dp[1<<maxvacc][maxvacc];
int ans1 = 0, ans2 = 1e9+7;

void self_min(int &a, int b){
	a = min(a, b);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> e >> m >> s;
	for (int i=1; i<=n; i++){
		char c;
		cin >> c;
		if (c == 'Y') vacc_nodes.push_back(i);
	}
	for (int i=0; i<=n; i++){
		for (int j=0; j<=n; j++){
			dist[i][j] = 1e9+7;
		}
	}
	for (int i=0; i<=n; i++) dist[i][i] = 0;
	for (int i=0; i<e; i++){
		int a, b, w;
		cin >> a >> b >> w;
		self_min(dist[a][b], w);
		self_min(dist[b][a], w);
	}
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				self_min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

	// tsp
	int nn = vacc_nodes.size();
	for (int i=0; i<(1<<nn); i++){
		for (int j=0; j<nn; j++){
			dp[i][j] = 1e9+7;
		}
	}
	for (int i=0; i<nn; i++) dp[(1<<i)][i] = dist[s][vacc_nodes[i]];
	for (int mask=1; mask<(1<<nn); mask++){
		if (__builtin_popcount(mask) == 1) continue;
		for (int u=0; u<nn; u++){
			for (int v=0; v<nn; v++){
				if (u == v) continue;
				self_min(dp[mask][v], dp[mask&(~(1<<v))][u]+dist[vacc_nodes[u]][vacc_nodes[v]]);
			}
		}
	}
	int st;
	for (int mask=1; mask<(1<<nn); mask++){
		for (int last=0; last<nn; last++){
			if (dp[mask][last] <= m){
				int pc = __builtin_popcount(mask);
				if (pc > ans1){
					ans1 = pc;
					ans2 = dp[mask][last];
					st = mask;
				}
				else if (pc == ans1){
					if (dp[mask][last] < ans2){
						ans2 = min(ans2, dp[mask][last]);
						st = mask;
					}
				}
			}
		}
	}
	// for (int i=0; i<nn; i++){
	// 	if (st&(1<<i)) cout << vacc_nodes[i] << " ";
	// }
	// cout << "\n";
	if (ans1 == 0) cout << "Gama tidak terselamatkan\n";
	else cout << ans1 << " " << m-ans2 << "\n";
}