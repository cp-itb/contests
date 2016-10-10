/**
 * Contest : INC 2016
 * Team    : GituKanYa
 * Author  : Jauhar Arifin
 * Problem : A - String Matching
 */

#include  <bits/stdc++.h>

using namespace std;

int n;
string p,s;

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for (int tc = 1; tc <= n; tc++) {
		cin>>p>>s;
		int i = 0;
		bool match = 0;
		while (i < (int) s.length() && !match) {
			if (p.length() > s.length() - i)
				break;
			int j = 0;
			for (; j < (int) p.length() && p[j] == s[i+j]; j++);
			if (j >= (int) p.length()) {
				match = 1;
				break;
			}
			i += j + 1;
		}
		cout<<"Case #"<<tc<<": "<<(match ? "YES":"NO")<<endl;
	}
	return 0;
}
