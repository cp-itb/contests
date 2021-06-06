/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Farras Faddila
 * Problem : antrean FindMart
 */

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e5;

ll fc[N + 5], ifc[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) { return fpow(a, MOD - 2); }

void init() {
    fc[0] = ifc[0] = 1;
    for (int i = 1; i <= N; i++) { fc[i] = (fc[i - 1] * i) % MOD; }
    for (int i = 1; i <= N; i++) { ifc[i] = inv(fc[i]); }
}

ll C(ll a, ll b) {
    if (a < 0 || b < 0 || a < b) return 0;
    ll ret = fc[a];
    ret = (ret * ifc[b]) % MOD;
    ret = (ret * ifc[a - b]) % MOD;
    return ret;
}

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> ar(m);
    ll A = 0;
    for (int i = 0; i < m; i++) {
        cin >> ar[i];
        A += 1LL * ar[i];
    }
    if (A + m - 1 > n) {
        cout << "Oi oi, Jaga Jarak" << '\n';
        return;
    }

    ll ans = 1;
    for (int i = 0; i < m; i++) {
        ans = (ans * fc[ar[i]]) % MOD;
    }
    ans = (ans * C(n - A, m - 1)) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}