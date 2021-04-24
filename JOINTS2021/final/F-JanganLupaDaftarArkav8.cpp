 /**
  * Contest : Joints 2021 Final
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Jauhar Wibisono
  * Problem : F - Kotak Hadiah
  */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4;
int n, b[maxn], q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	b[0] = 0;
	for (int i=1; i<n; i++) cin >> b[i];
	for (int i=2; i<n; i++){
		b[i] ^= b[i-1];
	}
	cin >> q;
	while (q--){
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		if (x == y) cout << 0 << "\n";
		else cout << (b[y-1]^b[x-1]) << "\n";
	}
}

/*
4
13 14 4
3
1 3
1 4
2 4

*/