/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : I See the One
 * Author  : Dicky Novanto
 * Problem : E - Inaccurate Report
 */

#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
int counter[10010];

void bfs(int node, int sisa, int parent) {
	int i,j;
	if(sisa == 0){
		counter[node]++;
		return;
	}
	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v != parent) {
			bfs(v, sisa-1, node);
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vi());
	for(i=0;i<(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}
	memset(counter,0,sizeof counter);

	for(i=0;i<m;i++){
		
		int asal, jarak;
		scanf("%d %d",&asal,&jarak);
		//bfs
		bfs(asal, jarak, -1);
	}
	int maks = 0;
	for(i=1;i<=n;i++){
		maks = max(maks, counter[i]);
	}
	printf("%d\n",maks);
	return 0;
};