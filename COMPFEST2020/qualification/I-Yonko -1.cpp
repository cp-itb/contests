/**
 * Contest	: COMPFEST 2020 Qualification
 * Team		: Yonko -1
 * Author	: Jauhar Wibisono
 * Problem	: B - Illusory Tree
 */

#include<bits/stdc++.h>
using namespace std;

const int maxn=100002;
int n, k, l, e=0;
set<pair<int,int>>edgl;
vector<int>adjl[maxn];
bool visit[maxn];
bool ans=1;

void dfs(int now, int prev){
	if (visit[now]) ans=0;
	visit[now]=1;
	for (int next : adjl[now]){
		if (next==prev) continue;
		dfs(next,now);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	cin >> k;
	for (int i=0;i<k;i++){
		int u, v;
		cin >> u >> v;
		edgl.insert({u,v});
	}
	cin >> l;
	for (int i=0;i<l;i++){
		int u, v;
		cin >> u >> v;
		if (edgl.count({u,v})) edgl.erase({u,v});
		else edgl.insert({u,v});
	}
	for (auto u : edgl){
		adjl[u.first].push_back(u.second);
		adjl[u.second].push_back(u.first);
	}
	if (edgl.size()!=n-1){
		cout << "Bukan pohon\n";
		return 0;
	}
	memset(visit,0,sizeof visit);
	dfs(1,0);
	cout << (ans ? "Pohon\n" : "Bukan pohon\n");
}