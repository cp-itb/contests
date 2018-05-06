/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : I See the One
 * Author  : Tony, Dicky
 * Problem : C - Raon and Candy
 */

#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);
 
int n,i,j,k,t,m;
int c;
string s[102];
vector<pii > permen[102];
int dp[102][2][1001];

int solve(int lantai, int kiri, int c){
	if(lantai==n){
		if(c > 0)
			return 10000000;
		return 0;
	}
	if(dp[lantai][kiri][c]==-1){
		if(c==0){
			dp[lantai][kiri][c] = 1 + solve(lantai+1, kiri, c);
		}
		else{
			int temp = 10000000;
			int candy =0;
			if(!kiri){
				for(int i=0;i<permen[lantai].size();++i){
					candy += permen[lantai][i].se;
					temp = min(temp, 2*(permen[lantai][i].fi) + solve(lantai+1, kiri, max(c - candy, 0)));
				}
			}
			else{
				for(int i=permen[lantai].size()-1;i>=0;--i){
					candy += permen[lantai][i].se;
					temp = min(temp, 2*(m+1-permen[lantai][i].fi) + solve(lantai+1, kiri, max(c - candy, 0)));
				}
			}
			temp = min(temp, m+1 + solve(lantai+1, 1-kiri, max(c - candy, 0)));
			dp[lantai][kiri][c] = 1 + min(solve(lantai+1, kiri, c), temp);
		}
	}
	return dp[lantai][kiri][c];
}

int main(){
	memset(dp, -1, sizeof dp);
	cin>>n>>m>>c;
	for(i=0;i<n;i++){
		cin>>s[n-i-1];
	}
	for(i=0;i<n;i++){
		for(j=1;j<=m;j++){
			if(s[i][j]>'0'){
				permen[i].pb({j, s[i][j]-'0'});
			}
		}
	}
	printf("%d\n", solve(0,0,c)-1);
	return 0;
}