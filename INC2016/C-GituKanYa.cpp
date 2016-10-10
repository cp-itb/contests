/**
 * Contest : INC 2016
 * Team    : GituKanYa
 * Author  : Jauhar Arifin
 * Problem : C - Beautiful Quadruple
 */

#include <bits/stdc++.h>

#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second.first
#define td second.second

using namespace std;

int t,n,m,p[150][150],h;
vector<int> memo[150][150];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	for (int tc = 1; tc <= t; tc++) {
		cin>>n>>m;
		map<int,int> hs;
		int tmp = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin>>p[i][j];
				if (hs.find(p[i][j]) == hs.end())
					hs[p[i][j]] = tmp++;
				p[i][j] = hs[p[i][j]];
			}
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				memo[i][j].clear();
			
		for (int j = 0; j < m; j++)
			for (int i = 0; i < n; i++)
				for (int k = i+1; k < n; k++)
					if (p[i][j] == p[k][j])
						memo[i][k].push_back(p[i][j]);
		
		h = 0;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++) {
				int *xx = (int*) malloc(tmp*4);
				for (int k = 0; k < tmp; k++)
					xx[k] = 0;
				for (int k = 0; k < (int) memo[i][j].size(); k++)
					h += ++(xx[memo[i][j][k]]) - 1;
				free(xx);
			}
			
		cout<<"Case #"<<tc<<": "<<h<<endl;
	}
	return 0;
}
