/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : I See the One
 * Author  : Tony
 * Problem : H - Captain Kaban
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
int e[10],f[10];

int main(){
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;cc++){
		printf("Case #%d: ", cc);
		scanf("%d", &n);
		int ans = 0;
		int a,b,c;
		for(int i=0;i<10;++i){
			scanf("%d %d %d", &a, &b, &c);
			e[i] = a+b+c;
			ans += e[i];
		}
		for(int i=0;i<n;++i){
			scanf("%d %d %d", &a, &b, &c);
			f[i] = a+b+c;
		}
		int wew = *max_element(f, f+n) - *min_element(e, e+10);
		if(wew>0)
			printf("%d\n", ans+wew);
		else
			printf("%d\n", ans);
	}
	return 0;
}