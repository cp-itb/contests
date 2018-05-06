#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

const bool debug = false;

int n,k,c;
double dp[1005][20];

int main() {
  scanf("%d%d%d", &n,&k,&c);
  for (int i=0; i<=n; i++) {
    for (int j=1; j<=c; j++) {
      dp[i][j] = 0;
      if (i == 0 && j == c) dp[i][j] = 1;
      if (i-k-1 >= 0) dp[i][j] += dp[i-k-1][1+(j+c-2)%c];
      if (i-k   >= 0) dp[i][j] += dp[i-k  ][1+(j+c-2)%c];
      if (k > 1 && i-k+1 >= 0) dp[i][j] += dp[i-k+1][1+(j+c-2)%c];
    }
  }
  if (dp[n][c] < 0) return 1;
  int e = 0;
  double ans = dp[n][c];
  while (ans >= 10) {
    e++;
    ans /= 10;
  }
  printf("%.3lf x 10^%d\n", ans, e);
}