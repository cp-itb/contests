/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : E
 */
#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const int L = ceil(log2(N)) + 2;
const ll INF = 1e18;

int n, m, q;
int par[N];
vector<pair<pair<int, int>, int>> edge_left;
vector<pair<int, int>> adj[N];
int up[N][L];
int tin[N], tout[N], tim;
long long depth[N];

int fpar(int u) {
    return (par[u] == u ? u : par[u] = fpar(par[u]));
}

bool merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return false;
    par[pv] = pu;
    return true;
}

void processLCA(int u, int p) {
    up[u][0] = p; tin[u] = ++tim;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto e : adj[u]) {
        int v = e.first, w = e.second;
        if (v == p) continue;
        depth[v] = depth[u] + w;
        processLCA(v, u);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) { 
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

long long distance(int u, int v) {
    int w = LCA(u, v);
    return depth[u] + depth[v] - 2LL * depth[w];
}

map<int, ll> jarsisa[N];

set<int> allsisa;
vector<int> nsisa;

ll ask(int a, int b){
    nsisa.push_back(a);
    nsisa.push_back(b);
    int len = nsisa.size();

    ll dp[len];
    fill(dp, dp + len, INF);
    dp[len - 2] = 0;

    set<pair<ll, int>> setdah;
    setdah.insert({0, len - 2});

    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.second;
        ll cur = tp.first;

        for (int i=0;i<len;i++){
            if (i == node) continue;
            ll jar = distance(nsisa[node], nsisa[i]);
            if (jarsisa[nsisa[node]].count(nsisa[i])) jar = min(jar, jarsisa[nsisa[node]][nsisa[i]]);

            if (dp[i] > dp[node] + jar){
                setdah.erase({dp[i], i});
                dp[i] = dp[node] + jar;
                setdah.insert({dp[i], i});
            }
        }
    }

    nsisa.pop_back();
    nsisa.pop_back();
    return dp[len - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (merge(u, v)) {
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        } else {
            allsisa.insert(u);
            allsisa.insert(v);
            if (jarsisa[u].count(v)) jarsisa[u][v] = min(jarsisa[u][v], (ll)w);
            else jarsisa[u][v] = (ll)w;
            if (jarsisa[v].count(u)) jarsisa[v][u] = min(jarsisa[v][u], (ll)w);
            else jarsisa[v][u] = (ll)w;
            edge_left.push_back({{u, v}, w});
        }
    }
    for (auto x : allsisa){
        nsisa.push_back(x);
    }
    processLCA(1, 1);
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ask(l, r) << '\n';
    }

    return 0;
}
