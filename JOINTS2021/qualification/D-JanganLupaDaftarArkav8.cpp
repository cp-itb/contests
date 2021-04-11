 /**
  * Contest : Joints 2021 Qualification
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Jauhar Wibisono
  * Problem : D - Jaringan Komputer
  */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4, maxa = 1e5+4;
int n;
vector<int> bucket[maxa];
int par[maxn], sez[maxn];
int ans1, ans2;

int find(int x){
	while (x != par[x]) x = par[x];
	return x;
}

void unite(int u, int v){
	u = find(u);
	v = find(v);
	if (sez[u] > sez[v]) swap(u, v);
	par[u] = v;
	sez[v] += sez[u];
}

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		int a;
		cin >> a;
		bucket[a].push_back(i);
	}
	ans1 = n;
	for (int i=1; i<=n; i++){
		par[i] = i;
		sez[i] = 1;
	}
	for (int i=2; i<maxa; i++){
		int u = -1;
		if (!bucket[i].empty()) u = bucket[i][0];
		for (int j=1; j<(int)bucket[i].size(); j++){
			int v = bucket[i][j];
			if (find(u) != find(v)){
				// cout << u << " " << v << "\n";
				unite(u, v);
				ans1--;
			}
		}
		for (int j=i+i; j<maxa; j+=i){
			for (int v : bucket[j]){
				if (u == -1) u = v;
				else if (find(u) != find(v)){
					// cout << u << " " << v << "\n";
					unite(u, v);
					ans1--;
				}
			}
		}
	}
	ans2 = 0;
	for (int i=1; i<=n; i++) ans2 = max(ans2, sez[i]);
	cout << ans1 << " " << ans2 << "\n";
}