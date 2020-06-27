/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : I See the One
 * Author  : Dicky Novanto
 * Problem : I - Irrigation
 */
#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 2e3+3;

int n,m;
int a[maxn][maxn];

int hitungJarak(int x1, int y1, int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(){
	int i,j;
	scanf("%d %d", &n, &m);
	int totalSemua = 0;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			scanf("%d", &a[i][j]);
			totalSemua += a[i][j];
		}
	}
	int vertikal[maxn], horizontal[maxn];
	
	for(j=1;j<=m;++j){
		for(i=1;j<=n;++i){
			if(i==1)
				vertikal[j] = a[i][j];
			else
				vertikal[j] += a[i][j];
		}
	}
	
	for(i=1;j<=n;++i){
		for(j=1;j<=m;++j){
			if(j==1)
				horizontal[i] = a[i][j];
			else
				horizontal[i] += a[i][j];
		}
	}
	
	int x,y;
	x = n/2;
	y = m/2;
	if(n%2==1)
		x++;
	if(m%2==1)
		y++;
	
	int maks = -inf;
	int jarakManhattanTerdekat = inf;
	int ansX = inf, ansY = inf;
	for(i=2;i<n;++i){
		for(j=2;j<m;++j){
			int total = totalSemua - vertikal[j] - horizontal[i] + a[i][j];
			int jarakDariPusat = hitungJarak(i,j,x,y);
			if(total>maks){
				maks = total;
				ansX = i; ansY = j;
				jarakManhattanTerdekat = jarakDariPusat;
			}else if(total == maks){
				if(jarakManhattanTerdekat > jarakDariPusat){
					jarakManhattanTerdekat = jarakDariPusat;
					ansX = i; ansY = j;
				}
				else if(jarakManhattanTerdekat == jarakDariPusat){
					if(ansX > i){
						ansX = i; ansY = j;
					}else if(ansX == i){
						if(ansY > j){
							ansX = i; ansY = j;
						}
					}
				}
			}
		}
	}
	
	printf("%d\n", maks);
	printf("%d %d\n", ansX, ansY);
	
	return 0;
}