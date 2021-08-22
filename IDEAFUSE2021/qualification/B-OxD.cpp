/**
 * Contest : Ideafuse 2021 Qualification
 * Team    : OxD
 * Author  : Jauhar Wibisono
 * Problem : B - Popular Searches
 */
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b){
	if (a.first.first != b.first.first) return a.first.first > b.first.first;
	if (a.first.second != b.first.second) return a.first.second > b.first.second;
	return a.second < b.second;
}

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> inp(n);
	map<string, int> conv;
	vector<string> conv2;
	for (int i=0; i<n; i++){
		int m;
		cin >> m;
		inp[i].resize(m);
		for (int j=0; j<m; j++){
			string s;
			cin >> s;
			if (!conv.count(s)){
				conv[s] = conv2.size();
				conv2.push_back(s);
			}
			inp[i][j] = conv[s];
		}
	}
	vector<int> cnt1, cnt2;
	for (int i=0; i<n; i++){
		sort(inp[i].begin(), inp[i].end());
		for (int l=0; l<(int)inp[i].size(); ){
			int r = l;
			while (r < (int)inp[i].size() && inp[i][r] == inp[i][l]) r++;
			cnt1.push_back(inp[i][l]);
			l = r;
		}
		for (int u : inp[i]) cnt2.push_back(u);
	}
	vector<pair<pair<int, int>, string>> ans;
	sort(cnt1.begin(), cnt1.end());
	sort(cnt2.begin(), cnt2.end());
	for (int l1=0, l2=0; l1<(int)cnt1.size() && l2<cnt2.size(); ){
		int r1 = l1;
		while (r1 < (int)cnt1.size() && cnt1[r1] == cnt1[l1]) r1++;
		int r2 = l2;
		while (r2 < (int)cnt2.size() && cnt2[r2] == cnt2[l2]) r2++;
		// assert(cnt1[l1] == cnt2[l2]);
		ans.push_back({{l1-r1, l2-r2}, conv2[cnt1[l1]]});
		l1 = r1; l2 = r2;
	}
	sort(ans.begin(), ans.end());
	for (int i=0; i<min(5, (int)ans.size()); i++) cout << ans[i].second << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	for (int tc=1; tc<=tcs; tc++){
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}