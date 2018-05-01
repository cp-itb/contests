/**
 * Contest : VOCOMFEST 2018 Qualification
 * Team    : I See The One
 * Author  : Tony
 * Problem : A - 3 Vertices 0TSP
 */

#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k;
string s;
int a;

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		printf("Case #%d: ", cc);
		ll n;
		scanf("%lld", &n);
		n%=10;
		printf("%lld\n", (3*n*n+3*n+1)%10);
	}
	return 0;
}
