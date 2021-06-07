/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : 0xD
 * Author  : Jauhar Wibisono
 * Problem : Jaga Jarak (upsolving, gak ac on contest)
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4;
int n;
long long d;
long long a[maxn];
long long ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> d;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i=0a; i<n; i++) a[i] -= d*i;
	priority_queue<long long> pq;
	pq.push(a[0]);
	for (int i=1; i<n; i++){
		pq.push(a[i]);
		if (pq.top() > a[i]){
			ans += pq.top()-a[i];
			pq.pop();
			pq.push(a[i]);
		}
	}
	cout << ans << "\n";
}