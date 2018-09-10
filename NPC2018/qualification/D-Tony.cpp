/**
 * Contest : NPC 2018 Qualification
 * Team    : Tony
 * Author  : Tony
 * Problem : D - Siapa Pasanganku
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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9;
const double pi = acos(-1);

int n,i,j,k,t;
set<int> s;

int main(){
	vector<int> v;
	while(scanf("%d", &n)==1){
		v.pb(n);
	}
	n = v.back();
	v.pop_back();
	for(i=0;i<v.size();++i){
		if(s.count(n-v[i]))
			return puts("ADA") & 0;
		s.insert(v[i]);
	}
	puts("TIDAK ADA");
	return 0;
}