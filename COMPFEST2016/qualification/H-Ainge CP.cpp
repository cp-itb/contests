/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : H - Badak Lompat
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int mod = 1e9 + 7;

int dp[2 * N][N][N][N];
int a[N][N][3], n;
int ti[3], tj[3], ni[3], nj[3];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

bool good(int i, int j, int k) {
  return !((i < j && j < k) || (i > j && j > k));
}

void normalize(int& v) {
  if (v >= mod) v -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for (int k = 0; k < 3; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          scanf("%d", &a[i][j][k]);
        }
      }
    }
    dp[0][0][0][0] = good(a[0][0][0], a[0][0][1], a[0][0][2]);
    int all = 2 * n - 1;
    for (int t = 0; t < all; t++) {
      //printf("%d\n", t);
      for (int i = 0; i < n; i++) {
        if (!valid(i, t - i)) continue;
        for (int j = 0; j < n; j++) {
          if (!valid(j, t - j)) continue;
          for (int k = 0; k < n; k++) {
            if (!valid(k, t - k)) continue;
            if (dp[t][i][j][k] == 0) continue; 
            ni[0] = i; ni[1] = j, ni[2] = k;
            nj[0] = t-i; nj[1] = t-j; nj[2] = t-k;
            for (int mask = 0; mask < (1 << 3); mask++) {
              bool nice = 1;
              for (int it = 0; it < 3; it++) {
                //printf("ni %d %d\n", ni[it], nj[it]);
                if (mask & (1 << it)) {
                  ti[it] = ni[it];
                  tj[it] = nj[it] + 1;
                } else {
                  ti[it] = ni[it] + 1;
                  tj[it] = nj[it];
                }
                if (!valid(ti[it], tj[it])) {
                  nice = 0;
                  break;
                }
                //printf("ti %d %d\n", ti[it], tj[it]);
              }
              if (!nice) continue;
              if (good(a[ti[0]][tj[0]][0], a[ti[1]][tj[1]][1], a[ti[2]][tj[2]][2])) {
                dp[t + 1][ti[0]][ti[1]][ti[2]] += dp[t][i][j][k];
                normalize(dp[t + 1][ti[0]][ti[1]][ti[2]]);
              }
            }
          }
        }
      }
    }
    printf("%d\n", dp[2*n-2][n-1][n-1][n-1]);
  }

  return 0;
}
