#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

struct item {
  item() {
    lef[0] = lef[1] = 0;
    rig[0] = rig[1] = 0;
    len = 0;
    best = 0;
  }
  void flip() {
    swap(lef[0], lef[1]);
    swap(rig[0], rig[1]);
  }
  void print() {
    printf("lef %d %d\n", lef[0], lef[1]);
    printf("rig %d %d\n", rig[0], rig[1]);
    printf("len %d best %d\n", len, best);
    printf("\n");
  }
  item& operator=(const item& other) {
    for (int i = 0; i < 2; i++) {
      lef[i] = other.lef[i];
      rig[i] = other.rig[i];
    }
    len = other.len;
    best = other.best;
    return (*this);
  }
  int lef[2];
  int rig[2];
  int len;
  int best;
};

item gabung(item l, item r) {
  item ret;
  for (int i = 0; i < 2; i++) {
    if (l.lef[i] == l.len) {
      ret.lef[i] = l.lef[i] + r.lef[i];
    } else {
      ret.lef[i] = l.lef[i];
    }
    if (r.rig[i] == r.len) {
      ret.rig[i] = r.rig[i] + l.rig[i];
    } else {
      ret.rig[i] = r.rig[i];
    }
    ret.best = max(ret.best, ret.lef[i]);
    ret.best = max(ret.best, ret.rig[i]);
    ret.best = max(ret.best, l.rig[i] + r.lef[i]);
  }
  ret.best = max(ret.best, l.best);
  ret.best = max(ret.best, r.best);
  ret.len = l.len + r.len;
  return ret;
}

struct segtree {
  segtree(int n) : n(n) {
    c.assign(n << 2, 0);
    num.resize(n << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      if (s[l] == '1') {
        num[p].lef[1] = 1;
        num[p].rig[1] = 1;
      } else {
        num[p].lef[0] = 1;
        num[p].rig[0] = 1;
      }
      num[p].len = 1;
      num[p].best = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = gabung(num[p+p], num[p+p+1]);
  }
  void relax(int p, int l, int r) {
    if (c[p]) {
      num[p].flip();
      if (l < r) {
        c[p + p] ^= 1;
        c[p + p + 1] ^= 1;
      }
      c[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    num[p] = gabung(num[p+p], num[p+p+1]);
  }
  void change(int l, int r) {
    change(1, 1, n, l, r);
  }
  void change(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      c[p] ^= 1;
      relax(p, l, r);
      //printf("%d %d %d %d %d\n", p, l, r, ll, rr);
      //num[p].print();
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    change(p + p, l, mid, ll, rr);
    change(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    //printf("%d %d %d %d %d\n", p, l, r, ll, rr);
    //num[p].print();
  }
  int find(int l, int r) {
    return find(1, 1, n, l, r).best;
  }
  item find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) {
      item ret;
      return ret;
    }
    int mid = (l + r) >> 1;
    item lef = find(p + p, l, mid, ll, rr);
    item rig = find(p + p + 1, mid + 1, r, ll, rr);
    item ret = gabung(lef, rig);
    combine(p, l, r);
    //printf("%d %d %d %d %d\n", p, l, r, ll, rr);
    //ret.print();
    return ret;
  }
  vector<int> c;
  vector<item> num;
  int n;
};

int main() {
  int n, q;
  scanf("%d %d %s", &n, &q, s + 1);
  segtree seg(n);
  while (q--) {
    //puts("---- GANTI TC -----");
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    //printf("testcase %d %d %d\n", t, l, r);
    if (t == 1) {
      seg.change(l, r);
    } else {
      printf("%d\n", seg.find(l, r));
    }
  }

  return 0;
}
