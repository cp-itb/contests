/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : D - Arithmetic Sequence
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int inf = 2e9;

int a[N];

struct segtree {
  segtree(int n) : n(n) {
    sip.resize(n << 2);
    d.resize(n << 2);
    build(1, 1, n);
  }
  void combine(int p, int l, int r) {
    int mid = (l + r) >> 1;
    int diff = a[mid + 1] - a[mid];
    if (d[p + p] == inf && d[p + p + 1] == inf) {
      sip[p] = 1;
      d[p] = diff;
    } else if (d[p + p] == inf) {
      sip[p] = (sip[p + p + 1] && (d[p + p + 1] == diff));
      d[p] = diff;
    } else if (d[p + p + 1] == inf) {
      sip[p] = (sip[p + p] && (d[p + p] == diff));
      d[p] = diff;
    } else {
      sip[p] = (sip[p + p] && sip[p + p + 1] && d[p + p] == d[p + p + 1] && diff == d[p + p]);
      d[p] = diff;
    }
  }
  void build(int p, int l, int r) {
    if (l == r) {
      sip[p] = 1;
      d[p] = inf;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void update(int at, int v) {
    update(1, 1, n, at, v);
  }
  void update(int p, int l, int r, int at, int v) {
    if (l == r) {
      a[l] = v;
      sip[p] = 1;
      d[p] = inf;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, v);
    } else {
      update(p + p + 1, mid + 1, r, at, v);
    }
    combine(p, l, r);
  }
  int find(int l, int r) {
    return find(1, 1, n, l, r).first;
  }
  pair<int, int> find(int p, int l, int r, int ll, int rr) {
    //printf("%d %d %d %d\n", l, r, ll, rr);
    if (ll <= l && r <= rr) {
      //printf("anjing %d %d dari %d %d\n", sip[p], d[p], l, r);
      return make_pair(sip[p], d[p]);
    }
    int mid = (l + r) >> 1;
    if (rr <= mid) {
      return find(p + p, l, mid, ll, rr);
    } else if (mid < ll) {
      return find(p + p + 1, mid + 1, r, ll, rr);
    } else {
      pair<int, int> lef = find(p + p, l, mid, ll, rr);
      pair<int, int> rig = find(p + p + 1, mid + 1, r, ll, rr);
      //printf("gabung %d %d %d\n", l, mid, mid + 1, r);
      //printf("%d %d\n", lef.first, rig.first);
      if (lef.first == 0 || rig.first == 0) return {0, inf};
      int diff = a[mid + 1] - a[mid];
      int ld = lef.second;
      int rd = rig.second;
      if (ld == inf && rd == inf) {
        return {1, diff};
      } else if (ld == inf) {
        return {rig.first && diff == rd, diff};
      } else if (rd == inf) {
        return {lef.first && diff == ld, diff};
      } else {
        return {ld == rd && ld == diff, diff};
      }
    }
  }
    
  vector<int> sip;
  vector<int> d;
  int n;
};

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    printf("Case #%d:\n", tt);
    
    segtree seg(n);
    while (q--) {
      int tc, l, r;
      scanf("%d %d %d", &tc, &l, &r);
      if (tc == 1) {
        seg.update(l, r);
      } else {
        bool ret = seg.find(l, r);
        puts(ret? "YES" : "NO");
      }
    }
  }
  
  return 0;
}