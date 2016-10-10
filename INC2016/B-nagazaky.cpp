/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Christ Angga Saputra
 * Problem : B - Compact Bag
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() {
	int f[1000]={0};
	int ntc, n, k;
	string a, b;
	
	cin >> ntc;
	for (int itc=1; itc<=ntc; ++itc) {
		cin >> n >> k;
		for (int i=0; i<n; ++i) {
			cin >> f[i];
		}

		int g[1000]={0};
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (i != j && f[i] >= f[j] && abs(f[i] - f[j]) <= k) {
					// cout << f[i] << " " << f[j] << endl;
					g[i]++;
				}
			}
		}

		// for (int i=0; i<n; ++i) {
		// 	cout << g[i] << " ";
		// }
		// cout << endl;

		int max = 0;
		for (int i=0; i<n; ++i) {
			if (g[i] > max) {
				max = g[i];
			}
		}

		cout << "Case #" << itc << ": " << max+1 << endl;
	}

	return 0;
}
