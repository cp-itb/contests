/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Morgen Sudyanto
 * Problem : D - Pembagi Ganjil Terbesar
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL solve(LL a, LL b, LL m) {
    a %= m, b %= m;
    LL n = sqrt(m) + 1;

    LL an = 1;
    for (LL i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<LL, LL> vals;
    for (LL q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (LL p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            LL ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL x;
        cin >> x;
        x *= 3;
        x %= MOD;
        x -= 2;
        x %= MOD;
        cout << solve(4,x,MOD) << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}