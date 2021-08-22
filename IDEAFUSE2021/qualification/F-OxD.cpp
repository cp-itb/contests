/**
 * Contest : Ideafuse 2021 Qualification
 * Team    : OxD
 * Author  : Jauhar Wibisono
 * Problem : F - Binary Classifier
 */
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
	return a.first.second > b.first.second;
}

void solve(){
	int n, q;
	cin >> n >> q;
	vector<pair<pair<int, int>, int>> a(n+q);
	for (int i=0; i<n; i++){
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = -1;	
	}
	for (int i=n; i<n+q; i++){
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i-n;
	}
	sort(a.begin(), a.end());
	vector<int> ans(q);
	for (int i=0; i<n+q; i++){
		if (a[i].second != -1){
			vector<pair<pair<int, int>, int>> tmp;
			int p;
			p = i;
			while (p < n+q && tmp.size() < a[i].first.second){
				if (a[p].second == -1) tmp.push_back({{abs(a[i].first.first - a[p].first.first), a[p].first.first}, a[p].first.second});
				p++;
			}
			p = i;
			while (p >= 0 && tmp.size() < a[i].first.second*2){
				if (a[p].second == -1) tmp.push_back({{abs(a[i].first.first - a[p].first.first), a[p].first.first}, a[p].first.second});
				p--;
			}
			sort(tmp.begin(), tmp.end(), cmp);
			vector<int> cnt(2, 0);
			for (int j=0; j<a[i].first.second; j++){
				cnt[tmp[j].second]++;
			}
			ans[a[i].second] = (cnt[0] > cnt[1] ? 0 : 1);
		}
	}
	for (int i=0; i<q; i++) cout << ans[i] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	for (int tc=1; tc<=tcs; tc++){
		cout << "Case #" << tc << ":\n";
		solve();
	}
	return 0;
}

/*
3
8 3

7 1
11 1
17 0
3 0
20 0
10 1
25 1
15 0

12 3
19 5
3 1

3 1
100 1
200 1
1000 1
17 1
5 2
34 0
91 1
25 0
70 1
52 0
61 1
61 3
*/