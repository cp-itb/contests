/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : I See the One
 * Author  : Tony
 * Problem : K - Echo Signal
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

int n;
int x[2003], y[2003], c[2003];
ll r;

ll dist(int i, int j){
	ll dx = x[i] - x[j];
	ll dy = y[i] - y[j];
	return dx*dx + dy*dy;
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int cc=1;cc<=tc;cc++){
		printf("Case #%d: ", cc);
		scanf("%d %lld", &n, &r);
		memset(c, 0, (n+1)<<2);
		r *= r;
		for(int i=0;i<n;++i)
			scanf("%d %d", x+i, y+i);
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				if(dist(i, j) <= r){
					++c[i];
					++c[j];
				}
			}
		}
		printf("%d\n", *max_element(c, c+n));
	}
	return 0;
}