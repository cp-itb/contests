 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Hasan
  * Problem : K
  */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int troops[2];
int a[N][2];
int len[2];
int gift[2];
bool dp[N][2];
long long sum[2];
long long res[2], ans[2];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int it = 0; it < 2; it++) {
        cin >> troops[it];
    }
    for (int it = 0; it < 2; it++) {
        cin >> len[it] >> gift[it];
        for (int i = 1; i <= len[it]; i++) {
            cin >> a[i][it];
            sum[it] += a[i][it];
        }
    }
    for (int it = 0; it < 2; it++) {
        int ot = (1 - it);
        dp[0][it] = true;
        for (int i = 1; i <= len[ot]; i++) {
            for (int val = gift[it]; val >= 0; val--) {
                if (val - a[i][ot] < 0) break;
                if (dp[val - a[i][ot]][it])
                    dp[val][it] = true;
            }
        }
        for (int val = gift[it]; val >= 0; val--) {
            if (dp[val][it]) {
                res[it] = val;
                break;
            }
        }
    }
    for (int it = 0; it < 2; it++) {
        int ot = (1 - it);
        ans[it] = sum[it] + res[it] - res[ot] + troops[it];
    }
    string condition;
    if (ans[0] > ans[1])
        condition = "Menang";
    else if (ans[0] < ans[1])
        condition = "Kalah";
    else
        condition = "Seri";
    cout << condition << '\n';
    cout << ans[0] << ' ' << ans[1] << '\n'; 

    return 0;
}