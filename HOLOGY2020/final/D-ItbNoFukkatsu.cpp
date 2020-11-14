/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Farras M. H. Faddila
 * Problem : D
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<string> ve = {"XXXS","XXS","XS","S","M","L","XL","XXL","XXXL"};
map<string, int> a, b;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[s]++;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    b[s]++;
  }
  int sama = 0;
  for (auto& t : ve) {
    sama += min(a[t], b[t]);
  }
  int ans = n - sama;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}