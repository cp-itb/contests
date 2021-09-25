/**
 * Contest : NPC Schemastics 2021
 * Team    : Ayam Bangkok Putih cs.
 * Author  : Jauhar Wibisono
 * Problem : D - Dihantam Pandemi
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n, m, a, b;
vector<pair<int, int>> adjl[maxn];
bool vis[maxn];
int dist1[maxn], dist2[maxn];
priority_queue<pair<int, int>> pq;
double ways1[maxn], ways2[maxn];
double ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> a >> b;
	for (int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adjl[u].emplace_back(v, w);
		adjl[v].emplace_back(u, w);
	}
	// dijkstra dari a
	memset(vis, 0, sizeof vis);
	for (int i=1; i<=n; i++){
		dist1[i] = 1e9+4;
		ways1[i] = 0;
	}
	dist1[a] = 0;
	ways1[a] = 1;
	pq.emplace(-dist1[a], a);
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto p : adjl[u]){
			int v = p.first, w = p.second;
			if (dist1[v] > dist1[u] + w){
				dist1[v] = dist1[u] + w;
				ways1[v] = ways1[u];
				pq.emplace(-dist1[v], v);
			}
			else if (dist1[v] == dist1[u] + w) ways1[v] += ways1[u];
		}
	}
	// dijkstra dari b
	memset(vis, 0, sizeof vis);
	for (int i=1; i<=n; i++){
		dist2[i] = 1e9+4;
		ways2[i] = 0;
	}
	dist2[b] = 0;
	ways2[b] = 1;
	pq.emplace(-dist2[b], b);
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto p : adjl[u]){
			int v = p.first, w = p.second;
			if (dist2[v] > dist2[u] + w){
				dist2[v] = dist2[u] + w;
				ways2[v] = ways2[u];
				pq.emplace(-dist2[v], v);
			}
			else if (dist2[v] == dist2[u] + w) ways2[v] += ways2[u];
		}
	}
	for (int i=1; i<=n; i++){
		if (dist1[i] + dist2[i] != dist1[b]) cout << fixed << setprecision(9) << 0.0 << '\n';
		else cout << fixed << setprecision(9) << ways1[i]/ways1[b] * ways2[i] * 2 << '\n';
	}
	return 0;
}