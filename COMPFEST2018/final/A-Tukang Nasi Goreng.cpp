/**
 * Contest : COMPFEST 2018 Final
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : A - Tumpukan Terbesar  
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5, inf = 1e9 + 7;

int hh[N], ll[N], rr[N];

set<pair<long long, int> > maks;
set<pair<int, int> > seg[N];

vector<int> vall;
int find(int x) {
  return lower_bound(vall.begin(), vall.end(), x) - vall.begin();
}

int ids;

void add(int h, int l, int r) {
  hh[ids] = h;
  ll[ids] = l;
  rr[ids] = r;
  maks.insert(make_pair(1LL * (r-l+1) * h, ids));
  seg[find(h)].insert(make_pair(l, ids));
  ++ids;
}

void del(int id) {
  seg[find(hh[id])].erase(make_pair(ll[id], id));
  maks.erase(make_pair(1LL * (rr[id]-ll[id]+1) * hh[id], id));
}

void rem(int hid, int pos, bool single) {
  auto it = seg[hid].upper_bound(make_pair(pos, inf));
  // cerr << hid << " " << seg[hid].size() << endl;
  if (it == seg[hid].begin()) return;
  --it;
  int l, r, id;
  id = it->second;
  l = it->first;
  r = rr[id];
  if (pos < l || pos > r) return;
  del(id);
  if (!single) return;
  if (l < pos)
    add(hh[id], l, pos-1);
  if (pos < r)
    add(hh[id], pos+1, r);
}

int c[N], v[N], a[N], b[N];

int mi[N << 2];
int n, q;

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    mi[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return inf;
  if (x <= l && r <= y) return mi[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

void update(int x, int y, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    mi[id] = y;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, y, il, l, mid);
  else
    update(x, y, ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);  
}

pair<int, int> get_seg(int pos) {
  int le = 0, ri = pos;
  while (le < ri) {
    int mid = (le + ri) >> 1;
    if (get(mid, pos+1) == a[pos])
      ri = mid;
    else
      le = mid+1;
  }
  int l = le;

  le = pos, ri = n-1;
  while (le < ri) {
    int mid = (le + ri+1) >> 1;
    if (get(pos, mid+1) == a[pos])
      le = mid;
    else
      ri = mid-1;
  }
  return make_pair(l, le);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < N; ++i)
      seg[i].clear();
    vall.clear();
    maks.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      vall.push_back(a[i]);
      b[i] = a[i];
    }
    for (int i = 0; i < q; ++i) {
      scanf("%d %d", c+i, v+i); --v[i];
      b[v[i]] += c[i];
      vall.push_back(b[v[i]]);
    }
    build();
    sort(vall.begin(), vall.end());
    vall.erase(unique(vall.begin(), vall.end()), vall.end());
    vector<tuple<int, int, int> > segall;
    for (int i = 0; i < n; ++i) {
      pair<int, int> inv = get_seg(i);
      segall.emplace_back(inv.first, inv.second, a[i]);
    }
    sort(segall.begin(), segall.end());
    segall.erase(unique(segall.begin(), segall.end()), segall.end());
    ids = 0;
    for (auto it : segall) {
      int l, r, h;
      tie(l, r, h) = it;
      // cerr << " add " << l << " " << r << " " << h << endl;
      add(h, l, r);
    }
    for (int i = 0; i < q; ++i) {
      int pos = v[i];
      int id = find(a[pos]);
      // cerr << " que " << i << endl;
      if (c[i] < 0)
        rem(id, pos, true);
      a[pos] += c[i];
      id = find(a[pos]);
      update(pos, a[pos]);
      pair<int, int> inv = get_seg(pos);
      // cerr << " new seg " << inv.first << " " << inv.second << endl;
      rem(id, inv.first, false);
      rem(id, inv.second, false);
      add(a[pos], inv.first, inv.second);
      assert(!maks.empty());
      printf("%lld\n", maks.rbegin()->first);
    }
  }
  return 0; 
}
