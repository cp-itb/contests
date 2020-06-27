/**
 * Contest : VOCOMFEST 2018 Final
 * Team    : Turfa Jauh Ya
 * Author  : Turfa Auliarachman
 * Problem : C - John, He is Your Uncle. Call Him Uncle Jack
 */

#include <bits/stdc++.h>

#define UNDEF 1000

using namespace std;

vector<string> names;
map<string, int> peringkat;
map<string, vector<string> > siblings;
map<string, string> pasangan;
map<string, string> ortu;
map<string, vector<string> > childs;
vector<string> ans;

void track(string now) {
	if (pasangan.find(now) != pasangan.end()) {
		if (peringkat[pasangan[now]] == UNDEF) {
			peringkat[pasangan[now]] = peringkat[now];
			track(pasangan[now]);
		}
	}
	if (ortu.find(now) != ortu.end()) {
		if (peringkat[ortu[now]] == UNDEF) {
			peringkat[ortu[now]] = peringkat[now]-1;
			track(ortu[now]);
		}
	}
	for (string child : childs[now]) {
		if (peringkat[child] == UNDEF) {
			peringkat[child] = peringkat[now]+1;
			track(child);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		names.push_back(s);
		peringkat[s] = UNDEF;
	}
	for (int i=1; i<n; i++) {
		string s, t, tmp;
		cin >> s >> tmp;

		if (tmp == "is") {
			cin >> t >> tmp;
			childs[t].push_back(s);
			ortu[s] = t;
		} else {
			cin >> t;
			pasangan[s] = t;
			pasangan[t] = s;
		}
	}

	string john;
	cin >> john;
	peringkat[john] = 0;
	track(john);

	for (string name: names) {
		if (peringkat[name] >= 0) ans.push_back(name);
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 1) {
		cout << "none" << endl;
	}

	for (string name : ans) {
		if (name != john) cout << name << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}