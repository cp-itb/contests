/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : B - Menggambar Molekul
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n, m;
char a[N][N];
char ans[N * 5][N * 5];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= 2 * (n + 1); i++) {
    for (int j = 1; j <= 3 * (m + 1); j++) {
      ans[i][j] = ' ';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '|') {
        ans[2 * i][3 * j] = ' ';
        ans[2 * i][3 * j + 1] = '|';
        ans[2 * i][3 * j + 2] = ' ';
        ans[2 * i + 1][3 * j] = ' ';
        ans[2 * i + 1][3 * j + 1] = '|';
        ans[2 * i + 1][3 * j + 2] = ' ';
      } else if (a[i][j] == '-') {
        ans[2 * i][3 * j] = '_';
        ans[2 * i][3 * j + 1] = '_';
        ans[2 * i][3 * j + 2] = '_';
        ans[2 * i + 1][3 * j] = ' ';
        ans[2 * i + 1][3 * j + 1] = ' ';
        ans[2 * i + 1][3 * j + 2] = ' ';
      } else {
        ans[2 * i][3 * j] = '/';
        ans[2 * i][3 * j + 1] = ' ';
        ans[2 * i][3 * j + 2] = '\\';
        ans[2 * i + 1][3 * j] = '\\';
        ans[2 * i + 1][3 * j + 1] = '_';
        ans[2 * i + 1][3 * j + 2] = '/';
      }
    }
  }
  for (int i = 1; i <= 2 * (n + 1); i++) {
    for (int j = 1; j <= 3 * (m + 1); j++) {
      if (ans[i][j] == ' ' && ans[i + 1][j - 1] == '/' && ans[i + 1][j + 1] == '\\') {
        ans[i][j] = '_';
      }
    }
  }
  for (int i = 1; i <= 2 * (n + 1); i++) {
    for (int j = 3; j <= 3 * (m + 1); j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }

  return 0;
}