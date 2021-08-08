 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Jauhar Wibisono
  * Problem : C - Portal dan Monster
  */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4;
int n, m;
long long a[maxn];
vector<int> adjl[maxn];
bool vis[maxn];
vector<long long> tot;
long long ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	memset(vis, 0, sizeof vis);
	for (int i=1; i<=n; i++){
		if (vis[i]) continue;
		long long sum = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty()){
			int u = q.front();
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			sum += a[u];
			for (int v : adjl[u]) q.push(v);
		}
		tot.push_back(sum);
	}
	sort(tot.rbegin(), tot.rend());
	ans = 0;
	for (int i=0; i<(int)tot.size(); i++) ans += tot[i] * (i+1);
	cout << ans << '\n';
	return 0;
}