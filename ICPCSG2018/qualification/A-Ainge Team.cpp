/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Luqman Arifin
 * Problem : A - Knight Search
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const string S = "ICPCASIASG";

char s[N][N];
char buf[N * N];

int n;

bool done[N][N][20];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  scanf("%d %s", &n, buf);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      s[i][j] = buf[i * n + j];
      done[i][j][0] = 1;
    }
  }

  for (int t = 0; t < S.size(); t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!done[i][j][t]) continue;
        for (int ti = -5; ti <= 5; ti++) {
          for (int tj = -5; tj <= 5; tj++) {
            if (ti*ti + tj*tj != 5) continue;
            int x = i + ti;
            int y = j + tj;
            if (!valid(x, y)) continue;
            if (s[x][y] == S[t]) {
              // printf("move %d %d to %d %d: %d %d: %c %c\n", i, j, x, y, x, y, s[x][y], S[t]);
              done[x][y][t + 1] = 1;
            }
          }
        }
      }
    }
  }
  bool sip = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (done[i][j][S.size()]) {
        // printf("%d %d: %d\n", i, j, i * n + j);
        sip = 1;
      }
    }
  }
  puts(sip? "YES" : "NO");
  return 0;
}
