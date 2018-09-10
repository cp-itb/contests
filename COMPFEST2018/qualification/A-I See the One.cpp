/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : I See the One
 * Author  : Tony
 * Problem : A - Origami Tempel 
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

template<class T>
struct mapper{
	std::vector<T> m;
	mapper(){}
	mapper(const T *arr, int sz){mapping(arr, sz);}
	mapper(const vector<T> &arr){mapping(arr);}
	void mapping(const vector<T> &arr){
		m.clear();
		for(int x : arr)
			m.pb(x);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(T val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
	int operator[] (T val){ return get(val);}
};

int n,i,j,k,t;
vector<int> adj[120002];
vector<int> wew;
pii a[60002];
int par[60002], cnt;
mapper<int> mep;

int find_set(int v){
	if(v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

int union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		cnt++;
		par[b] = a;
	}
}

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		scanf("%d", &n);
		for(i=0;i<n;++i){
			int x, y;
			scanf("%d %d", &x, &y);
			a[i] = {x, y};
			wew.pb(x);
			wew.pb(y);
			par[i] = i;
		}
		mep.mapping(wew);
		for(i=0;i<n;++i){
			a[i].fi = mep[a[i].fi];
			a[i].se = mep[a[i].se];
			adj[a[i].fi].pb(i);
			adj[a[i].se].pb(i);
		}
		ll ans = 0;
		for(i=0;i<mep.m.size();++i){
			if(adj[i].size()<=1)
				continue;
			cnt = 1;
			for(j=1;j<adj[i].size();++j){
				int x = adj[i][j-1];
				int y = adj[i][j];
					union_set(x, y);
			}
			ans += 1LL*mep.m[i]*(cnt-1);
		}
		printf("%lld\n", ans);
		wew.clear();
		for(i=0;i<mep.m.size();++i)
			adj[i].clear();
	}
	return 0;
}