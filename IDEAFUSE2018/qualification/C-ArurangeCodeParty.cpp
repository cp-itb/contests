/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : Arurange Code Party
 * Author  : Dewita Sonya
 * Problem : C - Raon and Candy
 */

#include <bits/stdc++.h>
using namespace std;

int n,m,c,sm=0;
char s;
int dp[110][110][1010],d[110][110],dt[110];
const int INF = 1000000000;

int main() {
    cin >> n >> m >> c;
    m += 2;
    for (int i=0;i<n;++i) {
        cin >> s;
        d[i][0] = 0;
        dt[i] = 0;
        for (int j=1;j<m-1;++j) {
            cin >> s;
            d[i][j] = s-'0';
            dt[i] += d[i][j];
        }
        cin >> s;
        d[i][m-1] = 0;
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            for (int k=0;k<=c;++k) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[n-1][0][0] = 0;
    for (int j=1;j<m-1;++j) {
        if (d[n-1][j]) {
            for (int k=sm+1;k<=min(sm+d[n-1][j], c);++k) {
                dp[n-1][0][k] = j+j;
            }
            sm += d[n-1][j];
        }
    }
    for (int k=0;k<=min(c, sm);++k) {
        dp[n-1][m-1][k] = m-1;
    }
    for (int i=n-2;i>=0;--i) {
        sm = 0;
        for (int j=0;j<m;++j) {
            dp[i][j][c] = min(dp[i+1][0][max(c-sm-d[i][j], 0)]+j+1, dp[i][j][c]);
            dp[i][j][c] = min(dp[i+1][m-1][max(c-dt[i]+sm, 0)]+m-j, dp[i][j][c]);
            for (int k=c-1;k>=0;--k) {
                dp[i][j][k] = min(dp[i][j][k], dp[i][j][k+1]);
                dp[i][j][k] = min(dp[i][j][k], dp[i+1][0][max(k-sm-d[i][j], 0)]+j+1);
                dp[i][j][k] = min(dp[i][j][k], dp[i+1][m-1][max(k-dt[i]+sm, 0)]+m-j);
            }
            sm += d[i][j];
        }
        for (int j=1;j<m-1;++j) {
            for (int k=0;k<=c;++k) {
                dp[i][0][k] = min(dp[i][0][k], dp[i][j][k]+j);
                dp[i][m-1][k] = min(dp[i][m-1][k], dp[i][j][k]+m-1-j);
            }
        }
    }
    cout << min(dp[0][0][c], dp[0][m-1][c]) << endl;
    return 0;
}