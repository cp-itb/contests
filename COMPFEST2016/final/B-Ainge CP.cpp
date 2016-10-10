/**
 * Contest : COMPFEST 2016 Final
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : B
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const long long inf = 1e16;
long long dp[N], le[N], ri[N];
int x[N][N];
deque< pair<int, long long> > dq[N];
bool y[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", x[i]+j);
      }
    }
    memset(y, false, sizeof y);
    for (int i = 0; i < m; i++) {
      int a;
      scanf("%d", &a);
      y[a-1] = true;
    }
    for (int i = 0; i < n; i++) {
      dp[i] = 0;
      dq[i].clear();
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[j] += x[i][j];
        // cerr << i << " " << j << " " <<  dq[j].size() << endl;
        if (!dq[j].empty()) {
          dp[j] = max(dp[j], x[i][j] + dq[j].front().second);
          // cerr << dq[j].front().second << endl;
        }
      }
      if (y[i]) {
        // cerr << i << " hero " << endl;
        le[0] = -inf;
        for (int j = 1; j < n; j++) {
          le[j] = max(dp[j-1], le[j-1]);
        }
        ri[n-1] = -inf;
        for (int j = n-2; j >= 0; j--) {
          ri[j] = max(dp[j+1], ri[j+1]);
        }
        for (int j = 0; j < n; j++) {
          long long now = max(le[j], ri[j]);
          while (!dq[j].empty() && dq[j].back().second < now) {
            dq[j].pop_back();
          }
          // cerr << j << " " << now << endl;
          dq[j].push_back(make_pair(i, now));
          // cerr << dq[j].size() << endl;
        }
      }
      if (i >= k && y[i-k]) {
        for (int j = 0; j < n; j++)
          if (!dq[j].empty() && dq[j].front().first == i-k)
            dq[j].pop_front();
      }
    }
    long long ans = -inf;
    for (int i = 0; i < n; i++)
      ans = max(ans, dp[i]);
    printf("%lld\n", ans);
  }
  return 0;
}