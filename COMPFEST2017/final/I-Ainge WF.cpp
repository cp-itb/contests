/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : I - Percobaan Median
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k;
int a[N], b[N];

vector<int> proc(int * x, int m) {
  vector<int> ret;
  int now = 0;
  for (int i = 0; i < n; i++) {
    now += x[i] <= m;
    if (i >= k)
      now -= x[i-k] <= m;
    if (i >= k-1)
      ret.push_back(now);
  }
  return ret;
}

bool can(int m) {
  vector<int> va = proc(a, m), vb = proc(b, m);
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  long long tot = (1LL * va.size() * vb.size()) / 2 + 1;
  for (int i = 0, j = (int)vb.size()-1; i < va.size(); i++) {
    while (j >= 0 && va[i] + vb[j] > k) j--;
    tot -= (int)vb.size()-1-j;
  }
  return tot <= 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    vector<int> v;
    for (int i = 0; i < n; i++)
      scanf("%d", a+i), v.push_back(a[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", b+i), v.push_back(b[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int l = 0, r = v.size()-1;
    while (l < r) {
      int m = (l + r)/2;
      if (can(v[m]))
        r = m;
      else
        l = m+1;
    }
    printf("%d\n", v[l]);
  }

  return 0;
}
