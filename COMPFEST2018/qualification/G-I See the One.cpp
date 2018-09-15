/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : I See the One
 * Author  : Tony
 * Problem : G - FPB Terbesar 
 */
 
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
int cnt[1000002];

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		memset(cnt, 0, sizeof cnt);
		scanf("%d %d", &n, &m);
		for(i=0;i<n;++i){
			int a, sq;
			scanf("%d", &a);
			sq = sqrt(a);
			for(j=1;a && j<=sq;++j){
				if(a%j==0){
					k = a/j;
					cnt[j]++;
					if(k!=j)
						cnt[k]++;
				}
			}
		}
		for(i=1000000;i>0;--i){
			if(cnt[i]>=m){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}