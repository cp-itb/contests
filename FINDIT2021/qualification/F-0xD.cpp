/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : 0xD
 * Author  : Jauhar Wibisono
 * Problem : To The Top
 */

#include <bits/stdc++.h>
using namespace std;

const int maxh = 55;
long long m, x, s;
int h;
long long a[maxh][maxh];
long long sum = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> x >> h >> s;
	a[h-1][0] = m;
	for (int r=h-1; r>=0; r--){
		if (r < h-1) a[r][0] = a[r+1][r+1]+x;
		for (int c=1; c<=r; c++) a[r][c] = a[r][c-1]+x;
	}
	for (int i=0; i<h; i++) sum += a[i][i];
	cout << ((s-sum) >= 0 ? "YA " : "TIDAK ") << abs(s-sum) << "\n";
}