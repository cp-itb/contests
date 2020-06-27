/**
 * Contest : VOCOMFEST 2018 Final
 * Team    : I See The One
 * Author  : Tony
 * Problem : H - The Multiplier Kendi
 */

#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define baca getchar_unlocked

typedef long long ll;
 
const ll mod = 1e9+9;
const double pi = acos(-1);
const int maxsz = 10;

int t, n;
ll a[11];
ll lomul, himul;

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%lld", a+i);
		himul = lomul = 1;
		for(int i=n-1;i>0;i--){
			lomul *= a[i];
			himul += lomul;
		}
		lomul *= a[0];
		ll fpb = __gcd(himul, lomul);
		printf("%lld\n", himul/fpb);
	}
	return 0;
}
