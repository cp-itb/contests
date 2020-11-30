/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : L
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int DIG = 10;
const int INF = 1e9;

int n, m;
int ar[N][N];
int pre[N][N][DIG];
int out[N][N][DIG];
int atas[N][N][DIG], kanan[N][N][DIG];

int hitung(int ra, int ca, int rb, int cb, int dig){
    if (rb < ra || cb < ca) return 0;
    return pre[rb][cb][dig] - pre[ra - 1][cb][dig] - pre[rb][ca - 1][dig] + pre[ra - 1][ca - 1][dig];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int cur[DIG];
        fill(cur, cur + DIG, 0);
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            ar[i][j] = c - '0';
            cur[ar[i][j]]++;
            for (int k=0;k<DIG;k++){
                pre[i][j][k] = pre[i - 1][j][k] + cur[k];
                atas[i][j][k] = kanan[i][j][k] = INF;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int k=0;k<DIG;k++){
                out[i][j][k] = hitung(1, 1, n, j - 1, k) + hitung(i + 1, j, n, m, k) + hitung(1, j + 1, i - 1, m, k);
                int del = (k - ar[i][j] + 10) % 10;
                if (i > 1) atas[i][j][k] = del + min(atas[i - 1][j][k], (k - ar[i - 1][j] + 10) % 10 + hitung(1, j, i - 2, j, k));
            }
        }
        for (int j=m;j>=1;j--){
            for (int k=0;k<DIG;k++){
                int del = (k - ar[i][j] + 10) % 10;
                if (j < m) kanan[i][j][k] = del + min(kanan[i][j + 1][k], (k - ar[i][j + 1] + 10) % 10 + hitung(i, j + 2, i, m, k));
            }
        }
    }
    int ans = INF;
    for (int i=2;i<=n;i++){
        for (int j=1;j<m;j++){
            for (int k=0;k<DIG;k++){
                int cur = min(ans, out[i][j][k] + atas[i][j][k] + kanan[i][j][k] - (k - ar[i][j] + 10) % 10);
                ans = min(ans, cur);
            }
        }
    }
    cout << ans << el;

    return 0;
}