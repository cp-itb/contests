/**
 * Contest : NPC 2018 Qualification
 * Team    : Dewita Sonya
 * Author  : Dewita Sonya
 * Problem : D - Siapa Pasanganku
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	unordered_map<int, int> m;
	vector<int> v;
	int n,x;
	getline(cin, s);
	x = 0;	
	for (auto c:s) {
		if (c==' ') {
			++m[x];
			v.push_back(x);
			x = 0;
		} else {
			x = 10*x+c-'0';
		}
	}
	++m[x];
	v.push_back(x);
	cin >> n;
	for (auto e:v) {
		if (e+e==n) {
			if (m[e]>=2) {
				puts("ADA");
				return 0;
			}
		} else {
			if (m[n-e]) {
				puts("ADA");
				return 0;
			}
		}
	}
	puts("TIDAK ADA");
	return 0;
}