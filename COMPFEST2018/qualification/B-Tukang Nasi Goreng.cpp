/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : Tukang Nasi Goreng
 * Author  : Luqman Arifin
 * Problem : B - Drone Pak Chanek 
 */

#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.);

int R;

double to_rad(int d) {
  return d * PI / 180;
}

double convert(double d) {
  if (d < 0) return -convert(-d);
  double rem = fmod(d, 4 * R);
  double base = ((int) (d / (4 * R))) * (4 * R);
  if (rem < R) {
    return d - base;
  } else if (rem < 3 * R) {
    return base + 2 * R - d;
  } else {
    return d - (base + 4 * R);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %d", &n, &R);
    double x = 0, y = 0;
    while (n--) {
      int d, dist;
      scanf("%d %d", &d, &dist);
      x += dist * cos(to_rad(d));
      y += dist * sin(to_rad(d));
      x = convert(x);
      y = convert(y);
    }
    printf("%.15f %.15f\n", x, y);
  }
  return 0;
}
