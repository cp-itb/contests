/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Luqman Arifin
 * Problem : L - Fair Tournament
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const int inf = 1e9;

int a[N][N];
vector<int> bit_to_mask[N];
bool pos[1 << N][N];
int cost[1 << N];

int dp[1 << N];

int main() {
  int n;
  scanf("%d", &n);
  int pw = 1;
  while (n--) pw *= 2;
  n = pw;

  for (int i = 0; i < (1 << n); i++) {
    bit_to_mask[__builtin_popcount(i)].push_back(i);
  }
  // for (int i = 0; i <= n; i++) printf("%d: %d\n", i, (int)bit_to_mask[i].size());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) pos[1 << i][i] = 1;
  for (int num = 1; 4 * num <= n; num *= 2) {
    for (auto i : bit_to_mask[num]) {
      for (auto j : bit_to_mask[num]) {
        if (i & j) continue;
        for (int x = 0; x < n; x++) {
          if (!pos[i][x]) continue;
          for (int y = 0; y < n; y++) {
            if (!pos[j][y]) continue;
            if (a[x][y] > 0) {
              pos[i | j][x] = 1;
            } else {
              pos[i | j][y] = 1;
            }
          }
        }
      }
    }
  }
  for (int j = 0; j < (1 << n); j++) {
    cost[j] = inf;
    for (int x = 0; x < n; x++) {
      if (pos[j][x] && a[0][x] > 0) {
        cost[j] = min(cost[j], a[0][x]);
      }
    }
  }

  fill(dp, dp + (1 << N), inf);
  dp[1] = 0;
  for (int num = 1; 4 * num <= n; num++) {
    for (auto i : bit_to_mask[num]) {
      if ((i & 1) == 0) continue;
      for (auto j : bit_to_mask[num]) {
        if (i & j) continue;
        dp[i | j] = min(dp[i | j], dp[i] + cost[j]);
      }
    }
  }
  int all = ((1 << n) - 1);
  for (auto i : bit_to_mask[n / 2]) {
    if ((i & 1) == 0) continue;
    int other = (all ^ i);
    // printf("%d %d: %d\n", dp[i], cost[other], dp[all]);
    dp[all] = min(dp[all], dp[i] + cost[other]);
  }
  if (dp[all] == inf) dp[all] = -1;
  cout << dp[all] << endl;
  return 0;
}
