/**
 * Contest : Ideafuse 2021 Final
 * Team    : Computer Saiyans
 * Author  : Jauhar Wibisono
 * Problem : F - Best Product
 */

#include <bits/stdc++.h>
using namespace std;

struct seg{
	long long mn, mx, mnr, mnl, mxr, mxl, prod;
	seg() {}
	seg(long long a) : mn(a), mx(a), mnr(a), mnl(a), mxr(a), mxl(a), prod(a) {}
	seg(seg l, seg r){
		if (l.prod == 0){
			mx = r.mx;
			mn = r.mn;
			mnr = r.mnr;
			mnl = r.mnl;
			mxr = r.mxr;
			mxl = r.mxl;
			prod = r.prod;
		}
		else if (r.prod == 0){
			mx = l.mx;
			mn = l.mn;
			mnr = l.mnr;
			mnl = l.mnl;
			mxr = l.mxr;
			mxl = l.mxl;
			prod = l.prod;
		}
		else{
			mx = max(l.mx, r.mx);
			mx = max(mx, l.mxr * r.mxl);
			mx = max(mx, l.mnr * r.mnl);
			mx = max(mx, l.mnr * r.mxl);
			mx = max(mx, l.mxr * r.mnl);

			mn = min(l.mn, r.mn);
			mn = min(mn, l.mnr * r.mxl);
			mn = min(mn, l.mxr * r.mnl);
			mn = min(mn, l.mxr * r.mxl);
			mn = min(mn, l.mnr * r.mnl);

			mnr = r.mnr;
			mnr = min(mnr, r.prod * l.mnr);
			mnr = min(mnr, r.prod * l.mxr);

			mnl = l.mnl;
			mnl = min(mnl, l.prod * r.mnl);
			mnl = min(mnl, l.prod * r.mxl);

			mxr = r.mxr;
			mxr = max(mxr, r.prod * l.mnr);
			mxr = max(mxr, r.prod * l.mxr);

			mxl = l.mxl;
			mxl = max(mxl, l.prod * r.mnl);
			mxl = max(mxl, l.prod * r.mxl);

			prod = l.prod * r.prod;
		}
	}
};

const int maxn = 1e5+4;
int n, q;
long long a[maxn];
seg tree[4*maxn];

void build(int l, int r, int v){
	if (l == r) tree[v] = seg(a[l]);
	else{
		int mid = (l+r)/2;
		build(l, mid, v*2);
		build(mid+1, r, v*2+1);
		tree[v] = seg(tree[v*2], tree[v*2+1]); 
	}
}

seg query(int l, int r, int v, int lb, int rb){
	if (r < lb || l > rb) return seg(0);
	if (l >= lb && r <= rb) return tree[v];
	int mid = (l+r)/2;
	return seg(query(l, mid, v*2, lb, rb), query(mid+1, r, v*2+1, lb, rb));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; i++) cin >> a[i];
	build(0, n-1, 1);
	// cout << "yey\n";
	// for (int l=0; l<n; l++){
	// 	for (int r=l; r<n; r++){
	// 		cout << "[" << l << "," << r << "] : " << query(0, n-1, 1, l, r).mx << '\n';
	// 	}
	// }
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << query(0, n-1, 1, l-1, r-1).mx << '\n';
	}
	return 0;
}

/*
2 0
-1 2

6 6
1 1 1 1 1 1
4 5
5 6
3 5
3 6
1 2
1 1

6 6
-1 -1 -1 -1 -1 -1
4 5
5 6
3 5
3 6
1 2
1 1

6 6
-2 -2 -2 -2 -2 -2
4 5
5 6
3 5
3 6
1 2
1 1

6 6
2 2 2 2 2 2
4 5
5 6
3 5
3 6
1 2
1 1
*/