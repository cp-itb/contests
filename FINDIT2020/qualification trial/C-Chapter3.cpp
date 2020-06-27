/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : C - Eternal Labyrinth
 */
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  int r, c;
  cin >> r >> c;
  int a[r + 5][c + 5];
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> a[i][j];
    }
  }
  if (a[1][1] == -1 || a[r][c] == -1) {
    cout << 0 << '\n';
    return 0;
  }
  int dp[r + 5][c + 5];
  memset(dp, 0, sizeof(dp));
  dp[1][1] = 1;
  a[1][1] = -1;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (a[i][j] == -1) continue;
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  cout << dp[r][c] << '\n';
 
  return 0;
} 