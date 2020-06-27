/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : F - Shady Antique Collector
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 33, K = 10, inf = 1e9;

int d[N][N][1<<K];
int dp[12][1<<K], dd[1<<K];
int r, c, k, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char s[N][N];

bool valid(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int solve(int n, int mask) {
  // cerr << n << " mask " << mask << endl;
  if (n == 0)
    return inf;
  if (mask == 0)
    return 0;
  int & ret = dp[n][mask];
  if (ret != -1)
    return ret;
  int lsb = mask & (-mask);
  ret = dd[mask] >= 0 ? dd[mask] : inf;
  mask ^= lsb;
  // if ((mask|lsb) == 23)
    // cerr << ret << " cuk " << endl;
  for (int i = mask; i > 0; i = (i-1) & mask) if (dd[i | lsb] >= 0) {
    // cerr << i << "-" << (mask^i) << " ";
    ret = min(ret, max(solve(n-1, mask ^ i), dd[i | lsb]));
    // if ((mask|lsb) == 23)
    //   cerr << (i | lsb) << " mask "<< endl;
  }
  if (dd[lsb] >= 0)
    ret = min(ret, max(solve(n-1, mask), dd[lsb]));
  return ret;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    scanf("%d %d %d %d", &r, &c, &k, &m);
    for (int i = 0; i < r; i++) {
      scanf("%s", s[i]);
    } 
    int a = 0, b = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (s[i][j] == 'E') {
          a = i;
          b = j;
          break;
        }
      }
    }
    queue < pair< pair<int , int >, int > > q;
    memset(d, -1, sizeof d);
    d[a][b][0] = 0;
    q.push({{a, b}, 0});
    // cerr << a << " E " << b << endl;
    while (!q.empty()) {
      auto it = q.front();
      int x = it.first.first, y = it.first.second, mask = it.second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!valid(xx, yy))
          continue;
        int cmask = mask;
        if (s[xx][yy] <= '9' && s[xx][yy] >= '0')
          cmask = mask | (1<< (s[xx][yy] - '0'));
        if (s[xx][yy] == '#' || d[xx][yy][cmask] != -1)
          continue;
        d[xx][yy][cmask] = d[x][y][mask] + 1;
        q.push({{xx, yy}, cmask});
      }
    }
    for (int i = 0; i < (1<<K); i++) {
      dd[i] = d[a][b][i];
      // if (dd[i] >= 0)
      //   cerr << i << " " << dd[i] << endl;
    }
    for (int i = 1; i < (1<<K); i++) {
      for (int j = i; j < (1<<K); j = (j+1) | i)
        if (dd[j] >= 0) {
          if (dd[i] == -1 || (dd[j] < dd[i]))
            dd[i] = dd[j];
        }
    }
    memset(dp, -1, sizeof dp);
    // for (int i = 0; i < 10; i++)
    //   for (int j = 0; j < (1<<K); j++)
    //     dp[i][j] = -1;
    int ans = inf;
    m = min(m, 10);
    for (int i = 0; i < (1<<K); i++) if (__builtin_popcount(i) >= k) {
      ans = min(ans, solve(m, i));
    }
    if (ans >= inf)
      ans = -1;
    // cerr << solve(m, 23) << " " << __builtin_popcount(23) << endl;
    printf("Case #%d: %d\n", tt, ans);
    // cerr << "hore" << endl;
  }
  return 0;
}