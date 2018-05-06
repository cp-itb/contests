/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : I See the One
 * Author  : Dicky Novanto
 * Problem : A - Nice Bro Aron
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

int main(){
	int n,i,j;
	int a[1010];
	scanf("%d",&n);
	int minim = inf;
	int sum = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); minim = min(minim, a[i]); sum+=a[i];}
	printf("%d\n",sum-minim);
	return 0;
};