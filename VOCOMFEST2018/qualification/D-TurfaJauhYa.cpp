/**
 * Contest : VOCOMFEST 2018 Qualification
 * Team    : TurfaJauhYa
 * Author  : Yonas Adiel
 * Problem : D - The Blangkon Code
 */
#include <cstdio>
#include <iostream>
using namespace std;

int translate(string st) {
	if (st == "#") return ' '-'A'+1;
	int r=0;
	int s=1;
	for (int i=st.length()-1; i>=0; i--) {
		if (st[i] == '-') {
			r += s;
			s <<= 1;
		} else if (st[i] == '.') {
			s <<= 1;
		}
	}
	return r;
}

void exec(int tc) {
	string kode;
	cin >> kode;

	printf("Case #%d: ", tc);
	string temp = "";
	for (int i=0; i<kode.length(); i++) {
		if (kode[i] == '-' || kode[i] == '.' || kode[i] == '#') {
			temp += kode[i];
		} else if (kode[i] == '/') {
			printf("%c", translate(temp)+'A'-1);
			temp = "";
		}
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		exec(i);
	}
}