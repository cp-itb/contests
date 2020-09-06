/**
 * Contest	: COMPFEST 2020 Qualification
 * Team		: Yonko -1
 * Author	: Jauhar Wibisono
 * Problem	: B - Bintang Ojol
 */

#include<bits/stdc++.h>
using namespace std;

long long n, m;

int main(){
	cin >> n >> m;
	if (n<m || n>5*m) cout << "-1 -1\n";
	else cout << max(0LL,n-4*m) << " " << min(m,(n-m)/4) << "\n";
}