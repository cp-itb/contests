/**
 * Contest : NPC 2018 Qualification
 * Team    : Tony
 * Author  : Tony
 * Problem : E - Bermain Tanah
 */

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int q;
pll tree[400002];
ll lazy[400002];
// ll a[100002];

void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
		scanf("%lld", &tree[node].fi);
    	tree[node].se = tree[node].fi; // Init value
		return;
	}
	
	build_tree(node*2+1, a, (a+b)/2); // Init left child
	build_tree(node*2+2, 1+(a+b)/2, b); // Init right child
	
	tree[node] = {max(tree[node*2+1].fi, tree[node*2+2].fi), min(tree[node*2+1].se, tree[node*2+2].se)}; // Init root value
}

void update_tree(int node, int a, int b, int i, int j, int value) {
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node].fi += lazy[node]; // Update it
   		tree[node].se += lazy[node]; // Update it
		if(a != b) {
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
    		lazy[node*2+2] += lazy[node]; // Mark child as lazy
		}
   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node].fi += value;
    		tree[node].se += value;

		if(a != b) { // Not leaf node
			lazy[node*2+1] += value;
			lazy[node*2+2] += value;
		}
    		return;
	}

	update_tree(1+node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(2+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = {max(tree[node*2+1].fi, tree[node*2+2].fi), min(tree[node*2+1].se, tree[node*2+2].se)}; // Updating root with max value
}

pll query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return {-INF, INF}; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node].fi += lazy[node]; // Update it
		tree[node].se += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
			lazy[node*2+2] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	pll q1 = query_tree(1+node*2, a, (a+b)/2, i, j); // Query left child
	pll q2 = query_tree(2+node*2, 1+(a+b)/2, b, i, j); // Query right child

	pll res = {max(q1.fi, q2.fi), min(q1.se, q2.se)}; // Return final result
	
	return res;
}
int main(){
	scanf("%d", &n);
	// for(i=0;i<n;++i)
		// scanf("%lld", a+i);
	build_tree(0, 0, n-1);
	scanf("%d", &q);
	while(q--){
		int op, l,r,v;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d %d %d", &l, &r, &v);
			update_tree(0, 0, n-1, l-1, r-1, v);
		}
		else{
			scanf("%d %d", &l, &r);
			pll res = query_tree(0, 0, n-1, l-1, r-1);
			printf("%lld\n", res.fi - res.se);
		}
	}
	return 0;
}