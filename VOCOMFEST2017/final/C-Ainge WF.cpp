/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Aufar Gilbran
 * Problem : C - Amazing Sequence
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 20

int a[MAXN+5];

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok = false;
    for (int i = 0; i < (1<<n) && !ok; ++i) {
      priority_queue<int> l, r;
      for (int j = 0; j < n; ++j) {
        if (i & (1<<j)) {
          if (a[j] > 0) l.push(a[j]);
        }
        else {
          if (a[j] > 0) r.push(a[j]);
        }
      }
      bool cek = true;
      while (!l.empty() && !r.empty() && cek) {
        int ll = l.top();
        l.pop();
        queue< int > q;
        while (ll-- > 0) {
          if (r.empty()) {
            cek = false;
            break;
          }
          int rr = r.top();
          rr--;
          r.pop();
          if (rr > 0)
            q.push(rr);
        }
        if (!cek) break;
        while (!q.empty()) {
          r.push(q.front()); q.pop();
        }
      }
      if (!l.empty() || !r.empty()) cek = false;
      if (cek)
        ok = true;
    }
    printf("Case #%d: %s\n", itc, (ok) ? "YES" : "NO");
  } 

  return 0;
}
