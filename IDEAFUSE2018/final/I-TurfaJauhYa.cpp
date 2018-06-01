/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Turfa Auliarachman
 * Problem : I - Irrigation
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000;

int sum[maxn+10][maxn+10];
int inp[maxn+10][maxn+10];
int n,m;

int prefsum(int a, int b, int c, int d) {
  int su = sum[c][d];
  if (b > 0) su -= sum[c][b-1];
  if (a > 0) su -= sum[a-1][d];
  if (a > 0 && b > 0) su += sum[a-1][b-1];
  return su;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  memset(sum, 0, sizeof sum);
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> inp[i][j];

      sum[i][j] = inp[i][j];
      if (i > 0) sum[i][j] += sum[i-1][j];
      if (j > 0) sum[i][j] += sum[i][j-1];
      if (i > 0 && j > 0) sum[i][j] -= sum[i-1][j-1];
    }
  }

  int ans = INT_MIN;
  int xsek = 10000, ysek=10000;

  for (int i=1; i<n-1; i++) {
    for (int j=1; j<m-1; j++) {
      int sumnow = prefsum(0,0,i-1,j-1);
      sumnow += prefsum(0,j+1,i-1,m-1);
      sumnow += prefsum(i+1,0,n-1,j-1);
      sumnow += prefsum(i+1,j+1,n-1,m-1);

      if (sumnow == ans) {
        if (abs(xsek+1-(n+1)/2) + abs(ysek+1-(m+1)/2) > abs(i+1-(n+1)/2) + abs(j+1-(m+1)/2)) {
          xsek = i; ysek = j;
        }
      } else if (sumnow > ans) {
        ans = sumnow;
        xsek = i; ysek = j;
      }
    }
  }
  cout << ans << endl;
  cout << xsek+1 << " " << ysek+1 << endl;
}