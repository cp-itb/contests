/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : F - Kartu Truf
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 50;

long long C[15][15][15];

int cnt[4][15];
char s[15][5], to[256];

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}


int main() {
  to['D'] = 0;
  to['C'] = 1;
  to['H'] = 2;
  to['S'] = 3;
  for (int i = 1; i < 9; i++)
    to['1' + i] = i;
  to['T'] = 9;
  to['J'] = 10;
  to['Q'] = 11;
  to['K'] = 12;
  to['A'] = 13;
  C[0][0][0] = 1;
  long long ma = 1, mi = 1;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      for (int k = 0; k < 15; k++) {
        if (i > 0) {
          int a = i + j + k, b = i;
          int d = gcd(a, b);
          a /= d; b/= d;
          C[i][j][k] = (C[i-1][j][k] / b) * a;
        }
        else if (j > 0) {
          int a = i + j + k, b = j;
          int d = gcd(a, b);
          a /= d; b/= d;
          C[i][j][k] = (C[i][j-1][k] / b) * a;
        }
        else if (k > 0) {
          int a = i + j + k, b = k;
          int d = gcd(a, b);
          a /= d; b/= d;
          C[i][j][k] = (C[i][j][k-1] / b) * a;
        }
        ma = max(ma, C[i][j][k]);
        mi = min(mi, C[i][j][k]);
      }
    }
  }
  // cerr << mi << " " << ma << endl;
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < 13; i++) {
      scanf("%s", s[i]);
      int x = to[s[i][1]], y = to[s[i][0]];
      cnt[x][y] = 1;
    }
    for (int i = 0; i < 13; i++) {
      int x = to[s[i][1]], y = to[s[i][0]];
      int a = y - 1, b = 13 - y;
      for (int j = 1; j < y; j++) {
        // cerr << cnt[x][j] << " ";
        a -= cnt[x][j];
      }
      for (int j = y + 1; j <= 13; j++) {
        // cerr << cnt[x][j] << " ";
        b -= cnt[x][j];
      }
      // cerr << s[i] << x << " " << y << " " << a << " " << b << endl;
      long long ans = 0;
      if (a == 0 && b == 0)
        ans += C[13][13][13];
      else {
        if (a >= 1)
          ans += 3LL * C[13][13][13-a-b];
        for (int j = 1; j < a; j++) {
          for (int k = 0; k <= b; k++) {
            ans += 3LL * C[13-j-k][13-a+j-b+k][13] * C[j][a-j][0] * C[k][b-k][0];
          }
        }
        for (int j = 1; j < a; j++) {
          for (int k = 1; k+j < a; k++) {
            for (int p = 0; p <= b; p++) {
              for (int q = 0; q + p <= b; q++) {
                ans += C[13-j-p][13-k-q][13-a+j+k-b+p+q] * C[j][k][a-j-k] * C[p][q][b-p-q];
              }
            }
          }
        }
      }
      double res = (double)ans/C[13][13][13];
      res *= 100;
      printf("%s: %.15lf%%\n", s[i], res);
    }
    printf("\n");
  }
  return 0;
}