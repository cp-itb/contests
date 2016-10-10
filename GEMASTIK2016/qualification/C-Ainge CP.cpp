/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : C - Menggemaskan dan Cantik
 */


#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

string s[N];
long long g[N], c[N];
int p[N];
long long ans;
int pa[N], pb[N];
int sa[N], sb[N];
vector<int> num;

bool cmp_g(int l, int r) {
  return g[l] > g[r];
}

bool cmp_c(int l, int r) {
  return c[l] > c[r];
}

void dfs(int i, int gn, int cn, long long gv, long long cv) {
  if (gn == 3 && cn == 3) {
    if (gv + cv > ans) {
      ans = gv + cv;
      for (int i = 0; i < 3; i++) {
        pa[i] = sa[i];
        pb[i] = sb[i];
      }
    }
    return;
  }
  if (i == num.size()) return;
  if (gn + 1 <= 3) {
    sa[gn] = num[i];
    dfs(i + 1, gn + 1, cn, gv * g[num[i]], cv);
  }
  if (cn + 1 <= 3) {
    sb[cn] = num[i];
    dfs(i + 1, gn, cn + 1, gv, cv * c[num[i]]);
  }
  dfs(i + 1, gn, cn, gv, cv);
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s[i] >> g[i] >> c[i];
      p[i] = i;
    }
    num.clear();
    
    sort(p, p + n, cmp_g);
    for (int i = 0; i < 6; i++) {
      num.push_back(p[i]);
      pa[i] = pb[i] = sa[i] = sb[i] = -1;
    }
    
    sort(p, p + n, cmp_c);
    for (int i = 0; i < 6; i++) {
      num.push_back(p[i]);
    }
    
    sort(num.begin(), num.end());
    num.resize(distance(num.begin(), unique(num.begin(), num.end())));
    //for(auto it : num) printf("%s\n", s[it].c_str());
    ans = 0;
    dfs(0, 0, 0, 1, 1);
    printf("%lld\n", ans);
    printf("%s %s %s\n", s[pa[0]].c_str(), s[pa[1]].c_str(), s[pa[2]].c_str());
    printf("%s %s %s\n", s[pb[0]].c_str(), s[pb[1]].c_str(), s[pb[2]].c_str());
  }
  
  return 0;
}
