/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : C - Beautiful Quadruple
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 155, M = 1e6;

int m[N][N];
int cnt[M];

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    int r, c;
    scanf("%d %d", &r, &c);
    vector< int > val;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", m[i]+j);
        val.push_back(m[i][j]);
      } 
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        m[i][j] = lower_bound(val.begin(), val.end(), m[i][j]) - val.begin();
      }
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
      for (int j = i+1; j < r; j++) {
        for (int k = 0; k < c; k++) {
          if (m[i][k] == m[j][k]) {
            ans += cnt[m[i][k]];
            cnt[m[i][k]]++;
          }
        }
        for (int k = 0; k < c; k++) {
          if (m[i][k] == m[j][k]) {
            cnt[m[i][k]] = 0;
          }
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}