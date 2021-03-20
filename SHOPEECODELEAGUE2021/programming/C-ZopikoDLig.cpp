/**
* Contest : Shopee Code League 2021
* Team    : ZopikoDLig
* Author  : Muhammad Kamal Shafi
* Problem : C
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

const int N = 1e4 + 10;
const int K = 110;
const ll INF = 1e18;

int n, k;
ll ar[N], pref[N];
ll dp[K][N];
long long C(int i, int j){
    return (pref[j] - pref[i - 1]) * ((ll)(j - i + 1));
}
void compute(int l, int r, int optl, int optr, int grup)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    pair<long long, int> best = {INF, -1};

    for (int i=optl;i<=min(mid, optr);i++){
        best = min(best, {dp[grup - 1][i] + C(i + 1, mid), i});
    }

    dp[grup][mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt, grup);
    compute(mid + 1, r, opt, optr, grup);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    k--;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pref[i] = pref[i - 1] + ar[i];
    }
    for (int i=0;i<K;i++){
        fill(dp[i] + 1, dp[i] + N, INF);
    }
    for (int i=1;i<=n;i++){
        dp[0][i] = C(1, i);
    }
    for (int i=1;i<=k;i++){
        compute(1, n, 0, n, i);
    }
    cout << dp[k][n] << el;

    return 0;
}