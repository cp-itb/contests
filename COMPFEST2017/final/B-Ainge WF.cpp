/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : B - Bersama Waifu
 */

#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-9;
struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {};
  bool operator==(point b) {
    return fabs(x - b.x) < eps && fabs(y - b.y) < eps;
  }
  bool operator<(point b) {
    if (fabs(y - b.y) > eps)
      return y < b.y;
    return x < b.x;
  }
};

long double cross(point a, point b, point c) {
  return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

long double dist2(point a, point b) {
  long double dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

bool diantara(point a, point b, point c) {
  if (fabs(cross(a, b, c)) > eps)
    return false;
  double le = dist2(a, c), ri = max(dist2(a, b), dist2(b, c));
  return le >= ri || fabs(le - ri) < eps || b == a || c == b;
}

struct line { long double a, b, c; };
void pointToLine(point p1, point p2, line *l) {
  if (fabs(p1.x - p2.x) < eps) {
    l->a = 1.0;
    l->b = 0.0;
    l->c = -p1.x;
  } 
  else {
    l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l->b = 1.0;
    l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
  }
}

bool areIntersect(line l1, line l2, point *p) {
  if (fabs(l1.a - l2.a) < eps && fabs(l1.b - l2.b) < eps)
    return false;
  p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > eps)
    p->y = - (l1.a * p->x + l1.c) / l1.b;
  else
    p->y = - (l2.a * p->x + l2.c) / l2.b;
  return true;
}

point pivot;

point p[505];
int n;
point a, b;

int process(point c, int lewat) {
    if (cross(a, c, b) < 0)
      swap(a, b);
    if (fabs(cross(a, c, b)) < eps) return n;
    int cntl = 0, cntr = 0, da = lewat >= 0, db = lewat >= 0, cc = lewat >= 0, la = 0, lb = 0;
    for (int j = 0; j < n; j++) {
      if (j == lewat) continue;
      long double ca = cross(a, c, p[j]), cb = cross(b, c, p[j]);
      if (fabs(ca) < eps || fabs(cb) < eps) {
        cc += fabs(ca) < eps && fabs(cb) < eps;
        if(diantara(a, p[j], c))
          da++;
        else if (diantara(p[j], a, c))
          la++;
        if (diantara(b, p[j], c))
          db++;
        else if (diantara(p[j], b, c))
          lb++;
        continue;
      }
      if (ca > eps && cb < -eps)
        cntl++;
      else
        cntr++;
    }
    int ans = n;
    int cur = cntl + da + db - cc;
    ans = min(ans, min(cur, n-cur));
    cur = cntl + la + db - cc;
    ans = min(ans, min(cur, n-cur));
    cur = cntl + da + lb - cc;
    ans = min(ans, min(cur, n-cur));
    cur = cntl + la + lb;
    ans = min(ans, min(cur, n-cur));
    // cerr << c.x << " " << c.y << " " << cntl << " " << da << " " << db << " " << la << " " << lb << endl;
    // cerr << ans << endl;
    return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      p[i] = point(x, y);
    }
    int x, y;
    scanf("%d %d", &x, &y);
    a = point(x, y);
    scanf("%d %d", &x, &y);
    b = point(x, y);
    int ans = n, dia = 0, le = 0, ri = 0;
    for (int i = 0; i < n; i++) {
      dia += diantara(a, p[i], b); 
      le += cross(a, b, p[i]) > eps;
      ri += cross(b, b, p[i]) < -eps;
    }
    ans = min(ans, min(dia, n-dia));
    ans = min(ans, min(le + dia, n-dia-le));
    ans = min(ans, min(ri + dia, n-dia-ri));
    for (int i = 0; i < n; i++) {
      if (fabs(cross(p[i], a, b)) > eps)
        ans = min(ans, process(p[i], i));
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        point c;
        line l1, l2;
        pointToLine(a, p[i], &l1);
        pointToLine(b, p[j], &l2);
        if (areIntersect(l1, l2, &c)) {
          ans = min(ans, process(c, -1));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
