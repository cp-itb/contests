/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Luqman Arifin
 * Problem : E - The Good, the Great, and the Superb
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

int a[N], cnt[10];
int bef[N][10], dp[N][10];
int pre[10][10][10][10];        // i, j, k, last

void upd(int& at, int val) {
  at = min(at, val);
}

int main() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          pre[i][j][k][l] = inf;
        }
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          for (int m = 0; m < 10; m++) {
            for (int n = 0; n < 10; n++) {
              if (abs(l - m) <= 1 && abs(m - n) <= 1) {
                upd(pre[i][j][k][n], (i != l) + (j != m) + (k != n));
              }
            }
          }
        }
      }
    }
  }

  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      bef[i][j] = dp[i][j] = inf;
    }
  }


  // kiri ke kanan
  for (int j = 0; j < 10; j++) {
    if (a[1] == j) {
      bef[1][j] = dp[1][j] = 0;
    } else {
      bef[1][j] = dp[1][j] = 1;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = j - 1; k <= j + 1; k++) {
        int cost = (j != a[i]);
        if (0 <= k && k <= 9) {
          upd(bef[i][j], bef[i-1][k] + cost);
        }
      }
    }
  }


  int superb = -1;
  for (int i = 0; i < 10; i++) superb = max(superb, cnt[i]);
  superb = n - superb;

  int great = inf;
  for (int j = 0; j < 10; j++) great = min(great, bef[n][j]);

  int good = min(superb, great);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = j - 1; k <= j + 1; k++) {
        if (0 <= k && k <= 9) {
          int cost = (k != a[i + 1]);
          upd(dp[i+1][k], dp[i][j] + cost);
        }
      }
    }
    if (i + 3 <= n && i >= 3) {
      int now = inf;
      for (int j = 0; j < 10; j++) upd(now, dp[i][j]);

      for (int j = 0; j < 10; j++) {
        upd(dp[i+3][j], now + pre[a[i+1]][a[i+2]][a[i+3]][j]);
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j < 10; j++) printf("%d ", dp[i][j]); printf("\n");
  // }
  for (int j = 0; j < 10; j++) upd(good, dp[n][j]);

  printf("%d %d %d\n", good, great, superb);
  return 0;
}
