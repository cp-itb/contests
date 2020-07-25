/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Rata
* Author  : Wiwit Rifai
* Problem : E - Wifi Network
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N];

void upd(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}

int get(int x) {
  int ret = 0;
  for (++x; x; x -= x&-x)
    ret += bit[x];
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  int xg[2], yg[2];
  scanf("%d %d %d %d", xg, yg, xg+1, yg+1);
  vector<long long> vd[2];
  vector<pair<long long, long long>> events(n);
  for (int i = 0; i < n; ++i) {
    long long d[2];
    for (int j = 0; j < 2; ++j) {
      long long dx = x[i] - xg[j];
      long long dy = y[i] - yg[j];
      d[j] = dx * dx + dy * dy;
      vd[j].push_back(d[j]);
    }
    events[i] = make_pair(d[0], d[1]);
  }
  for (int i = 0; i < 2; ++i)
    sort(vd[i].begin(), vd[i].end());
  int q;
  scanf("%d", &q);
  vector<int> ans(q);
  vector<tuple<int, int, int>> queries(q);
  for (int i = 0; i < q; ++i) {
    int r[2];
    scanf("%d %d", r, r+1);
    ans[i] = 0;
    for (int j = 0; j < 2; ++j) {
      int pos = upper_bound(vd[j].begin(), vd[j].end(), 1LL * r[j] * r[j]) - vd[j].begin();
      ans[i] += pos;
    }
    queries[i] = make_tuple(r[0], r[1], i);
  }
  for (int i = 0; i < 2; ++i) {
    vd[i].erase(unique(vd[i].begin(), vd[i].end()), vd[i].end());
  }
  sort(queries.begin(), queries.end());
  sort(events.begin(), events.end());
  int iter = 0;
  for (auto it : queries) {
    int ra, rb, id;
    tie(ra, rb, id) = it;
    long long da = 1LL * ra * ra;
    long long db = 1LL * rb * rb;
    while (iter < n && events[iter].first <= da) {
      int pos = lower_bound(vd[1].begin(), vd[1].end(), events[iter].second) - vd[1].begin();
      upd(pos, +1);
      ++iter;
    }

    int pos = upper_bound(vd[1].begin(), vd[1].end(), db) - vd[1].begin() - 1;
    ans[id] -= 2 * get(pos);
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", n - ans[i]);
  return 0;
}