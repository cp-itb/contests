/**
 * Contest : NPC Schemastics 2021
 * Team    : Ayam Bangkok Putih cs.
 * Author  : Jauhar Wibisono
 * Problem : C - Covid-21
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4;
int n;
string s[maxn];
int a[maxn];
int mx_score;
vector<string> best2;
string ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> s[i] >> a[i];
	// coba digit 0..9
	int mx_score = 0;
	for (int i='1'; i<='9'; i++){
		for (int j='0'; j<='9'; j++){
			// coba ij
			int score = 0;
			for (int k=0; k<n; k++){
				bool ok = false;
				for (int l=1; l+1<=4; l++){
					if (s[k][l] == i && s[k][l+1] == j) ok = true;
				}
				if (ok) score += a[k];
			}
			if (score >= mx_score){
				if (score > mx_score) best2.clear();
				string t;
				t.push_back(i);
				t.push_back(j);
				best2.push_back(t);
				mx_score = score;
			}
		}
	}
	sort(best2.begin(), best2.end());
	ans = best2[0];
	for (string &b : best2){
		// coba expand t, ke belakang aja cukup
		queue<string> q;
		q.push(b);
		while (!q.empty()){
			string t = q.front();
			q.pop();
			if (stoi(t) > stoi(ans)) ans = t;
			if (t.length() > 3) continue;
			for (int i='0'; i<='9'; i++){
				string tt = t;
				tt.push_back(i);
				int score = 0;
				for (int k=0; k<n; k++){
					bool ok = false;
					for (int l=1; l+(int)tt.size()<=5; l++){
						if (s[k].substr(l, (int)tt.size()) == tt) ok = true;
					}
					if (ok) score += a[k];
				}
				if (score == mx_score){
					q.push(tt);
				}
			}
		}
	}
	cout << 'V' << ans << '\n';
	return 0;
}

/*
3
B1234 10
B1234 20
B4321 100

3
B1000 10
B1000 20
B2000 100

3
B1234 100
B5678 10
B5678 20

3
B4321 10
B4321 20
B1234 100

3
B4392 10
B4392 20
B9201 100

3
B4392 10
B4392 20
B9201 100
*/