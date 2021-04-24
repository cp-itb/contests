/**
  * Contest : Joints 2021 Final
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Jauhar Wibisono
  * Problem : H - Pituber
  */

#include <bits/stdc++.h>
using namespace std;

const int maxk = 1e5+5;
long long m, c, t;
int k;
vector<pair<long long, long long>> good, bad;
int cntk = 0;

bool cmp(pair<long long, long long> aa, pair<long long, long long> bb){
	if (aa.second-aa.first != bb.second-bb.first) return aa.second-aa.first > bb.second-bb.first;
	return aa.first < bb.first;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> c >> t >> k;
	m -= c+t;
	for (int i=0; i<k; i++){
		long long h, v;
		cin >> h >> v;
		if (h > v) bad.push_back({h, v});
		else good.push_back({h, v});
	}

	sort(good.begin(), good.end());
	for (auto content : good){
		if (m >= content.first){
			m += content.second-content.first;
			cntk++;
		}
	}

	sort(bad.begin(), bad.end(), cmp);
	for (auto content : bad){
		if (m >= content.first){
			m += content.second-content.first;
			cntk++;
		}
	}
	
	if (cntk == 0) cout << "Gagal\n";
	else cout << cntk << " " << m << "\n";
}