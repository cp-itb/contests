/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : I - JogJek's Order
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 50050;
const long double eps = 1e-7, PI = acos(-1);
const double d60 = PI/4;
int n;
double r;

struct point {
  double x, y;
  point(double x = 0.0, double y = 0.0) : x(x), y(y) {};
};
double dist(point a, point b) {
  double dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}
bool zero(double x) {
  return fabs(x) < eps;
}

bool used[N];
point p[N];
point t, pivot;
bool cmp(int l, int r) {
  double al = atan2(p[l].y-pivot.y, p[l].x-pivot.x),
  ar = atan2(p[r].y-pivot.y, p[r].x-pivot.x);
  return al < ar;
}
double rad(point a, point b, point c) {
  double angle_a = atan2(a.y-b.y, a.x-b.x);
  double angle_c = atan2(c.y-b.y, c.x-b.x);
  double diff = angle_c-angle_a;
  while (diff < -eps) diff += 2 * PI;
  return diff;
}

bool crowded(int x, int need = 2) {
  if (need <= 0) return 1;
  used[x] = 1;
  vector< int > id;
  for (int i = 0; i < n; i++) {
    if (i == x || used[i]) continue;
    double d = dist(p[i], p[x]);
    if (d < r || zero(d-r))
      id.push_back(i);
  }
  if (id.size() >= need)
    return true;
  for (int i : id) {
    if (crowded(i, need-1))
      return true;
  }
  used[x] = 0;
  return false;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d %lf", &n, &r);
    r *= 2.0;
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    scanf("%lf %lf", &t.x, &t.y);
    bool ok = false;
    vector< int > id;
    for (int i = 0; i < n; i++) {
      double d = dist(p[i], t);
      if (d < r || zero(d-r))
        id.push_back(i); 
    }
    pivot = t;
    sort(id.begin(), id.end(), cmp);
    int now = 0, cnt = 0;
    memset(used, 0, sizeof used);
    for (int i = 0; i < id.size(); i++) {
      while (1) {
        if (cnt >= id.size()) break;
        double d = rad(p[id[i]], t, p[id[now]]);
        if (d > d60 || zero(d-d60))
          break;
        now = (now + 1) % id.size();
        cnt++;
        if (now == i)
          break;
      }
      if (cnt > 2)
        ok = 1;
      cnt = max(0, cnt-1);
    }
    if (!ok) {
      for (int i : id)
        if (crowded(i)) {
          ok = 1;
          break;
        }
    }
    printf("Case #%d: %s\n", tc, ok ? "ACCEPT" : "DENY");
  }
  return 0;
}
