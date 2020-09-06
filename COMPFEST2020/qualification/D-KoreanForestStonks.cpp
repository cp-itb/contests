/**
 * Contest : COMPFEFST XII 2020
 * Team    : Korean Forest Stonks
 * Author  : Michel Fang, Morgen Sudyanto
 * Problem : D - Distribusi Kelompok
 */
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 998244353;
const ll INF = 1e18;
const ll IINF = 1e9;

const int N = 1e6 + 5;

ll fpow(ll a, int b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ret * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return ret;
}

int n;
int ar[N];
ll f[N], inv[N];

void init() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (i * f[i - 1]) % MOD;
    }
    for (int i = 0; i < N; i++) {
        inv[i] = fpow(f[i], MOD - 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n;
    int tot = 0;
    map<int, ll> cnt;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
        tot += ar[i];
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll cur = f[tot] * inv[ar[i]] % MOD;
        cur = (cur * inv[tot - ar[i]]) % MOD;
        ans = (ans * cur) % MOD;
        tot -= ar[i];
    }
    for (auto it: cnt) {
        ans =  (ans * inv[it.se]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}