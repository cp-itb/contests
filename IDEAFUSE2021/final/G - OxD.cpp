/**
 * Contest : Ideafuse 2021 Final
 * Team    : Computer Saiyans
 * Author  : Jauhar Wibisono
 * Problem : G - Bounded Jump
 */

#include <bits/stdc++.h>
using namespace std;

int query(vector<int> &tree, int l, int r, int v, int lb, int rb){
	if (r < lb || l > rb) return 0;
	if (l >= lb && r <= rb) return tree[v];
	int mid = (l+r)/2;
	return max(query(tree, l, mid, v*2, lb, rb), query(tree, mid+1, r, v*2+1, lb, rb));
}

void update(vector<priority_queue<pair<int, int>>> &vpq, vector<int> &tree, int l, int r, int v, int idx){
	if (l == r) tree[v] = (vpq[l].empty() ? 0 : vpq[l].top().first);
	else{
		int mid = (l+r)/2;
		if (idx <= mid) update(vpq, tree, l, mid, v*2, idx);
		else update(vpq, tree, mid+1, r, v*2+1, idx);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
}

void solve(int tc){
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> a(n), sa(n);
	for (int i=0; i<n; i++){
		cin >> a[i];
		sa[i] = a[i];
	}
	sort(sa.begin(), sa.end());
	vector<priority_queue<pair<int, int>>> vpq(n);
	vector<int> tree(4*n, 0);
	int ans = 0;
	for (int i=0; i<n; i++){
		int lb = lower_bound(sa.begin(), sa.end(), a[i]-k) - sa.begin();
		int ub = lower_bound(sa.begin(), sa.end(), a[i]+k+1) - sa.begin() - 1;
		int idx = lower_bound(sa.begin(), sa.end(), a[i]) - sa.begin();
		int best = query(tree, 0, n-1, 1, lb, ub);
		ans = max(ans, best+1);
		// cout << lb << ' ' << ub << ' ' << idx << ' ' << best << '\n';
		pair<int, int> cp = {best+1, i};
		vpq[idx].push(cp);
		update(vpq, tree, 0, n-1, 1, idx);
		if (i >= l){
			int prev_idx = lower_bound(sa.begin(), sa.end(), a[i-l]) - sa.begin();
			// cout << prev_idx << '\n';
			pair<int, int> dummy = {1e9, -1e9};
			while (!vpq[prev_idx].empty() && vpq[prev_idx].top().second <= i-l) vpq[prev_idx].pop();
			update(vpq, tree, 0, n-1, 1, prev_idx);
		}
	}
	cout << "Case #" << tc << ": " << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	for (int tc=1; tc<=tcs; tc++){
		solve(tc);
	}
	return 0;
}