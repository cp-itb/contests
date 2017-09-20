/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : B - Half-Life 3 Confirmed
 */

#include <bits/stdc++.h>

using namespace std;

struct point{
  long long x, y;
  point(long long x = 0, long long y = 0) : x(x), y(y) {}
};
const int N = 202;
point p[N];

long long dist(point a, point b) {
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

long long dp[N][N];
long long solve(int l, int r){
  if (r-l <= 2) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  long long & ret = dp[l][r];
  ret = min(dist(p[l+1], p[r]) + solve(l+1, r), dist(p[l], p[r-1]) + solve(l, r-1));
  for (int i = l+2; i < r-1; i++) {
    ret = min(ret, dist(p[l], p[i]) + dist(p[i], p[r]) + solve(l, i) + solve(i, r));
  }
  return ret;
}

int main(){
  int t;
  scanf("%d", &t);
  for (int tc =1 ; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    memset(dp, -1, sizeof dp);
    printf("Case #%d: %lld\n", tc, solve(0, n-1));
  }
  return 0;
}
