/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : B
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

const int N = 1e7 + 10;
const ll INF = 1e18;

int n;
ll dp[N];
ll x, y;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(dp, dp + N, INF);
    dp[0] = 0;

    cin >> n >> x >> y;
    dp[1] = x;
    for (int i=2;i<=n;i++){
        if (i & 1){
            dp[i] = dp[i - 1] + x;
        } else{
            dp[i] = min(dp[i / 2] + y, dp[i - 1] + x);
        }
    }
    cout << dp[n] << el;

    return 0;
}