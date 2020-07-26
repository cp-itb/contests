/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Emeurgence
* Author  : Jehian Norman Saviero
* Problem : B - Shopee Logistics
*/

/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>
 
// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std
 
Jehian Norman Saviero;
 
// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
 
// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")
 
// MACROS FOR ATTRIBUTE
#define fi first
#define se second
 
// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))
 
// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

const int sz = 1e6+5;
bool visit[sz];
ll dist[sz];
vi adj[sz];
map<pi, ll> val;
int N;

pll bfs(int p) {
	queue<pll> q;
	q.push({p, 0});
	while (!q.empty()) {
		ll curr, cost;
		tie(curr, cost) = q.front();
		q.pop();
		if (!visit[curr]) {
			visit[curr] = 1;
			dist[curr] = cost;
			for (auto &nx : adj[curr]) {
				if (!visit[nx]) {
					q.push({nx, cost + val[{curr, nx}]});
				}
			}
		}
	}
	pll MAX = {-1, -1};
	for (int i = 0; i < N; ++i) {
		MAX = max(MAX, {dist[i], i});
	}
	return MAX;
}

int main() {
	sci(N);
	for (int i = 1; i < N; ++i) {
		ll u, v, c;
		scll(u), scll(v), scll(c);
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
		val[{u,v}] = c;
		val[{v,u}] = c;
	}
	RESET(visit);
	RESET(dist);
	pll leafs = bfs(0);

	RESET(visit);
	RESET(dist);
	pll second_leafs = bfs(leafs.se);

	// hapus node leafs
	RESET(visit);
	visit[leafs.se] = 1;
	RESET(dist);
	dist[leafs.se] = -1;
	pll ans_1 = bfs(second_leafs.se);

	// hapus node second_leafs
	RESET(visit);
	visit[second_leafs.se] = 1;
	RESET(dist);
	dist[second_leafs.se] = -1;
	pll ans_2 = bfs(leafs.se);
	printf("%lld\n", max(ans_1.fi, ans_2.fi));
	return 0;
}