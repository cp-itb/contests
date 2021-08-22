/**
 * Contest : Ideafuse 2021 Qualification
 * Team    : OxD
 * Author  : Jauhar Wibisono & Kinantan Arya Bagaspati
 * Problem : D - Gifted Kids
 */
#include <bits/stdc++.h>
using namespace std;

#define left qwpoemjqpwoeic
#define right mojqcweopmkjqcwpimo

const int maxn = 2e5+4, maxq = 2e5+4, sqrtq = sqrt(maxq);
vector<pair<int, int>> que;
int n, q;
long long a[maxn];
long long left[maxn], right[maxn], rightot[maxn];

void sweep(){
    // apply semua update di que
    long long curadd = 0;
    long long currange = 0;
    for(int i=0; i<maxn; i++){
        left[i] = 0;
        right[i] = 0;
        rightot[i] = 0;
    }
    for(int i=0; i<que.size(); i++){
        left[que[i].first]++;
        right[que[i].second]++;
        rightot[que[i].second]+=(que[i].second-que[i].first+1);
    }
    for(int i=0; i<maxn; i++){
        currange += left[i];
        curadd += currange;
        a[i] += curadd;
        curadd -= rightot[i];
        currange -= right[i];
    }
    que.clear();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; i++) cin >> a[i];
	while (q--){
		char type;
		cin >> type;
		if (type == 'A'){
			int l, r;
			cin >> l >> r;
			l--; r--;
			que.emplace_back(l, r);
		}
		else{
			int x;
			cin >> x;
			x--;
			long long ans = a[x];
			for (auto p : que){
				if (x >= p.first && x <= p.second) ans += 1LL * (x-p.first+1);
			}
			cout << ans << '\n';
		}
		if (que.size() == sqrtq) sweep();
	}
	return 0;
}