/**
 * Contest : Compfest 13 Qualification
 * Team    : Computer Saiyans
 * Author  : Jauhar Wibisono
 * Problem : Cari Perpotongan
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> get_rel(vector<int> &pre, vector<int> &nex){
	int n = pre.size();
	vector<int> ret(n);
	vector<int> pos(n+1);
	for (int i=0; i<n; i++) pos[pre[i]] = i+1;
	for (int i=0; i<n; i++) ret[i] = pos[nex[i]];
	return ret;
}

long long get_sum(vector<long long> &bit, int pos){
	long long ret = 0;
	while (pos > 0){
		ret += bit[pos];
		pos -= pos&-pos;
	}
	return ret;
}

void update(vector<long long> &bit, int pos){
	int n = bit.size();
	while (pos < n){
		bit[pos]++;
		pos += pos&-pos;
	}
}

long long count_inversion(vector<int> &a){
	int n = a.size();
	vector<long long> bit(n+1, 0);
	long long ret = 0;
	for (int i=0; i<n; i++){
		ret += get_sum(bit, n) - get_sum(bit, a[i]);
		// cout << get_sum(bit, n) - get_sum(bit, a[i]) << '\n';
		update(bit, a[i]);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> p(m, vector<int>(n));
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> p[j][i];
		}
	}
	long long ans = 0;
	for (int i=1; i<m; i++){
		vector<int> a = get_rel(p[i-1], p[i]);
		// for (int u : a) cout << u << ' ';
		// cout << '\n';
		ans += count_inversion(a);
	}
	cout << ans << '\n';
	return 0;
}