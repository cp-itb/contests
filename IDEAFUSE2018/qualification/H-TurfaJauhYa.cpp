#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

const bool debug = false;
vector<int> v;
vector<int> ans;

int main() {
  int x;
  while (cin >> x) {
    v.push_back(x);
  }
  int cnt = 1;
  bool first = true;
  string s = "";
  for (int i=1; i<v.size()+1; i++) {
    if (i == v.size() || cnt == 255 || v[i] != v[i-1]) {
      ans.push_back(cnt);
      ans.push_back(v[i-1]);
      cnt = 0;
    }
    cnt++;
  }
  printf("%d\n", ans.size());
  for (int i=0; i<ans.size(); i++) {
    if (i!=0) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
}