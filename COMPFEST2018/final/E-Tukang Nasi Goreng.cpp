/**
 * Contest : COMPFEST 2018 Final
 * Team    : Tukang Nasi Goreng
 * Author  : Luqman Arifin
 * Problem : E - Persegi Putar    
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 6e4 + 5;
const long long inf = 1e18;

struct segtree {
  segtree(int n) : n(n) {
    num.resize(n << 2);
    push.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    num[p] = inf;
    push[p] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }

  inline void relax(int p, int l, int r) {
    if (push[p] != 0) {
      num[p] += push[p];
      if (l < r) {
        push[p + p] += push[p];
        push[p + p + 1] += push[p];
      }
      push[p] = 0;
    }
  }
  inline void combine(int p, int l, int r) {
    num[p] = min(num[p + p] + push[p + p], num[p + p + 1] + push[p + p + 1]);
  }

  void update(int x, long long val) {
    // printf("update %d %lld\n", x, val);
    update(1, 0, n - 1, x, val);
  }
  void add(int l, int r, long long val) {
    // printf("add %d %d %lld\n", l, r, val);
    add(1, 0, n - 1, l, r, val);
  }
  long long find(int l, int r) {
    return find(1, 0, n - 1, l, r); 
  }
  void update(int p, int l, int r, int x, long long val) {
    relax(p, l, r);
    if (x < l) return;
    if (r < x) return;
    if (l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, x, val);
    update(p + p + 1, mid + 1, r, x, val);
    combine(p, l, r);
  }
  void add(int p, int l, int r, int ll, int rr, long long val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] += val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    add(p + p, l, mid, ll, rr, val);
    add(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return inf;
    int mid = (l + r) >> 1;
    long long ret = min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
    combine(p, l, r);
    return ret;
  }
  vector<long long> num, push;
  int n;
};

int orien[] = {-1, 1};
long long ans[N];
map<int, int> mx, my;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) ans[i] = inf;

    int n, q;
    scanf("%d %d", &n, &q);
    // x - y - id
    vector<tuple<int, int, int>> ori;
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      ori.emplace_back(x, y, -1);
    }
    for (int i = 0; i < q; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      ori.emplace_back(x, y, i);
    }
    for (int dx = 0; dx < 2; dx++) {
      for (int dy = 0; dy < 2; dy++) {
        // printf("\norientasi %d %d\n", orien[dx], orien[dy]);
        mx.clear();
        my.clear();
        vector<tuple<int, int, int>> a;
        vector<int> px, py;
        for (auto it : ori) {
          int x, y, id;
          tie(x, y, id) = it;

          a.emplace_back(x * orien[dx], y * orien[dy], id);
          px.push_back(x * orien[dx]);
          py.push_back(y * orien[dy]);
        }
        
        sort(a.begin(), a.end());
        sort(px.begin(), px.end());
        sort(py.begin(), py.end());

        px.erase(unique(px.begin(), px.end()), px.end());
        py.erase(unique(py.begin(), py.end()), py.end());
        for (int i = 0; i < px.size(); i++) mx[px[i]] = i;
        for (int i = 0; i < py.size(); i++) my[py[i]] = i;

        segtree seg(py.size());
        for (int k = 0; k < a.size(); k++) {
          int til = k;
          while (til + 1 < a.size() && get<0>(a[til + 1]) == get<0>(a[til])) til++;

          // for (int i = 0; i < py.size(); i++) printf("%lld ", seg.find(i, i)); printf("\n");
          for (int i = k; i <= til; i++) {
            int x, y, id;
            tie(x, y, id) = a[i];
            // printf("process %d %d %d\n", x, y, id);
            if (id == -1) {
              seg.update(my[y], -y);
            } else {
              long long ret = y + seg.find(0, my[y]);
              ans[id] = min(ans[id], ret);
            }
          }
          // for (int i = 0; i < q; i++) printf("%lld ", ans[i]); printf("\n");

          k = til;
          if (k + 1 < a.size()) {
            int d = get<0>(a[k + 1]) - get<0>(a[k]);
            seg.add(0, (int) py.size() - 1, d);
          }
        }
      }
    }
    for (int i = 0; i < q; i++) printf("%lld\n", 2 * ans[i]);
  }
  return 0; 
}
