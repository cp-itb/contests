/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Christ Angga Saputra
 * Problem : A - String Matching
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int ntc, n, m;
	string a, b;
	
	cin >> ntc;
	for (int itc=1; itc<=ntc; ++itc) {
		cin >> a >> b;

		bool isFound = true;
		int index = 0;
		while (index < b.size()) {
			bool isFound = true;
			for (int j=0; j<a.size(); ++j) {
				// cout << a[j] << " " << b[j+index] << endl;
				if (a[j] != b[j + index]) {
					isFound = false;
					index += j+1;
					break;
				}
			}

			if (isFound) {
				cout << "Case #" << itc << ": " << "YES" << endl;
				break;
			}
		}

		if (index >= b.size()) {
			cout << "Case #" << itc << ": " << "NO" << endl;
		}
	}

	return 0;
}
