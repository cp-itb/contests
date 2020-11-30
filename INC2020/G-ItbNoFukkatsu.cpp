/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : G
 */
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

const int N = 1e4 + 10, M = 210;
const ll MOD = 998244353;

int n;
vector<pil> adj[N];

ll dp[N]; // possibility count, count of item
ll pval[N];

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}
ll inv(ll a){
    return fpow(a, MOD - 2);
}
ll fac[N * M * 2];

void dfs(int node, int p){
    ll tot = 0;
    vector<ll> vec;
    ll base = 1;
    for (auto x : adj[node]){
        if (p == x.fi) continue;
        pval[x.fi] = x.se;
        dfs(x.fi, node);
        vec.pb(x.se);
        tot += x.se;
        base = base * dp[x.fi] % MOD;
    }
    ll temp = fac[tot];
    for (auto x : vec){
        temp = temp * inv(fac[x]) % MOD;
    }
    temp = temp * base % MOD;
    if (node != p){
        ll temp2 = fac[tot + pval[node] - 1];
        temp2 = temp2 * inv(fac[tot]) % MOD;
        temp2 = temp2 * inv(fac[pval[node] - 1]) % MOD;
        temp = temp * temp2 % MOD;
    }
    dp[node] = temp;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (int i=1;i<N * M * 2;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        w /= 2;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    dfs(1, 1);
    cout << dp[1] << el;

    return 0;
}