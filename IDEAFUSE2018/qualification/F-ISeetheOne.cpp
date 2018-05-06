/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : I See the One
 * Author  : Tony
 * Problem : F - Thumb Up Thumb Down Cute Cat
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

int main(){
	scanf("%d %d", &n, &k);
	int a = n+k;
	int b = n-k;
	if((a&1) || (b&1) || b<0 || a<0 || n<0)
		puts("NO");
	else 
		puts("YES");
	return 0;
}