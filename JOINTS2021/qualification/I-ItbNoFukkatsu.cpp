/**
  * Contest : Joints 2021 Qualification
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Kamal Shafi
  * Problem : I
***/
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
const int K = 12;
const int INF = 1e9 + 10;

int n, m, k, p; // target, panah, elemen, pinalti
int ar[K][K];
int target[N];
int panah[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> p;
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            cin >> ar[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        cin >> target[i];
    }
    for (int i=1;i<=m;i++){
        cin >> panah[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
    dp[0][0] = 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (i == 0 && j == 0) continue;
            int bi = i - 1;
            int bj = j - 1;
            if (bi >= 0){
                dp[i][j] = max(dp[i][j], dp[bi][j] - p);
            }
            if (bj >= 0){
                dp[i][j] = max(dp[i][j], dp[i][bj] - p);
            }
            if (bi >= 0 && bj >= 0){
                dp[i][j] = max(dp[i][j], dp[bi][bj] + ar[target[i]][panah[j]]);
            }
        }
    }
    cout << dp[n][m] << el;

    return 0;
}