/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : 0xD
 * Author  : Jauhar Wibisono
 * Problem : Berhitung
 */

#include <bits/stdc++.h>
using namespace std;

int t(int k, int n){
	if (k == 1) return 0;
	return (t(k-1,n) + n)%k;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	cout << t(n+1, n+1) + 1 << "\n";
}
