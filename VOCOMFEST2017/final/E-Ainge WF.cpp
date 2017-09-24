/**
 * Contest : VOCOMFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : E - Triangles
 */

#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-7;

struct point {
  double x, y;
  point (double x, double y) : x(x), y(y) {}
};

double cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

point lineIntersect(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u)/(u + v), (p.y*v + q.y * u)/(u+v));
}

vector< point > cutPolygon(point a, point b, vector< point > Q) {
  vector< point > P;
  for (int i = 0; i < (int)Q.size(); i++) {
    double left1 = cross(a, b, Q[i]), left2 = 0.0;
    if (i != (int)Q.size()-1) left2 = cross(a, b, Q[i+1]);
    if (left1 > -EPS) P.push_back(Q[i]);
    if (left1 * left2 < -EPS)
      P.push_back(lineIntersect(Q[i], Q[i+1], a, b));
  }
  if (P.empty()) return P;
  if (fabs(P.back().x - P.front().x) > EPS || fabs(P.back().y - P.front().y) > EPS)
    P.push_back(P.front());
  return P;
}
double area(const vector< point > & P) {
  double ret = 0;
  for (int i = 0; i < (int)P.size() - 1; i++) {
    ret += (P[i].x * P[i+1].y - P[i].y * P[i+1].x);
  }
  return fabs(ret)/2.0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    vector< point > a, b;
    for (int i = 0; i < 3; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      a.push_back(point(x, y));
    }
    for (int i = 0; i < 3; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      b.push_back(point(x, y));
    }
    if (cross(a[0], a[1], a[2]) <= -EPS)
      swap(a[1], a[2]);
    if (cross(b[0], b[1], b[2]) <= -EPS)
      swap(b[1], b[2]);
    b.push_back(b.front());
    a.push_back(a.front());
    for (int i = 0; i < 3; i++) {
      b = cutPolygon(a[i], a[i+1], b);
    }
    printf("Case #%d: %.6lf\n", tc, area(b));
  }
  return 0;
}
