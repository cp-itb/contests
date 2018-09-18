/**
 * Contest : COMPFEST 2018 Final
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : F - Musuh Udara    
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 3014;

const long double eps = 1e-5;

int ma[N << 2], add[N << 2];
int nseg;

void upd(int id, int v) {
  ma[id] += v;
  add[id] += v;
}

void push(int id) {
  if (add[id] == 0) return;
  int il = id << 1, ir = il | 1;
  upd(il, add[id]);
  upd(ir, add[id]);
  add[id] = 0;
}

void build(int id = 1, int l = 0, int r = nseg) {
  ma[id] = add[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = nseg) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}


void updsingle(int x, int v, int id = 1, int l = 0, int r = nseg) {
  if (r-l < 2) {
    ma[id] = v;
    return;
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    updsingle(x, v, il, l, mid);
  else
    updsingle(x, v, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

int get(int x, int y, int id = 1, int l = 0, int r = nseg) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    // cerr << l << " " << r << " " << ma[id] << endl;
    return ma[id];
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int dp[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);
    vector<pair<double, double> > seg;
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (y > r) continue;
      long long dx = 1LL * r * r - 1LL * y * y;
      double d = sqrt(dx);
      seg.emplace_back(x - d, x + d);
    }
    vector<double> all;
    for (auto it : seg) {
      all.push_back(it.first);
      all.push_back(it.second);
    }
    sort(all.begin(), all.end());
    vector<double> vx;
    if (!all.empty())
      vx.push_back(all[0]);
    for (auto x : all) {
      if (fabs(x-vx.back()) > eps) {
        vx.push_back(x);
      }
    }
    vector<pair<int, int> > inv;
    for (auto it : seg) {
      int l = lower_bound(vx.begin(), vx.end(), it.first-eps) - vx.begin();
      int r = lower_bound(vx.begin(), vx.end(), it.second-eps) - vx.begin();
      // cerr << l << " " << r << endl;
      assert(l <= r);
      inv.emplace_back(l, r);
    }
    sort(inv.begin(), inv.end());
    int ans = 0;
    for (int it = 1; it <= k; ++it) {
      nseg = vx.size()+1;
      build();
      priority_queue<pair<int, int> > pq;
      for (int i = 0, j = 0; i < vx.size(); ++i) {
        // cerr << " bef " << 0 << " " << i+1 << " " << get(0, i+1) << endl;
        while (j < inv.size() && inv[j].first <= i) {
          // cerr << " add " << 0 << " " << i+1 << endl;
          update(0, i+1, 1);
          pq.emplace(-inv[j].second, inv[j].first);
          ++j;
        }
        while (!pq.empty() && -pq.top().first < i) {
          // cerr << " rem " << 0 << " " << pq.top().second+1 << endl;
          update(0, pq.top().second+1, -1);
          pq.pop();
        }
        int best = dp[it][i] = get(0, i+1);
        // cerr << " dp " << it << " " << i << " " << best << endl;
        ans = max(ans, best);
        updsingle(i+1, dp[it-1][i]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
