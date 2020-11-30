/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi, Muhammad Hasan
 * Problem  : B
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
const int M = 2e4 + 10;
const int INT_INF = 1e9 + 10;
const long long INF = 1e18;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = INF;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].emplace_back(m);
        adj[u].emplace_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.emplace(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int) adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.emplace(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int n, m;
vector<pii> adj[N];
vector<int> nadj[N];

int dp1[N], dp2[N], ndp[N];
int in[N];

bool qual[N];

void preproc(){
    fill(dp1, dp1 + n + 1, INT_INF);
    set<pii> setdah;
    dp1[1] = 0;
    setdah.insert(mp(0, 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        int cur = tp.fi;
        for (auto x : adj[node]){
            if (dp1[x.fi] > cur + x.se){
                setdah.erase(mp(dp1[x.fi], x.fi));
                dp1[x.fi] = cur + x.se;
                setdah.insert(mp(dp1[x.fi], x.fi));
            }
        }
    }
    fill(dp2, dp2 + n + 1, INT_INF);
    dp2[n] = 0;
    setdah.insert(mp(0, n));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        int cur = tp.fi;
        for (auto x : adj[node]){
            if (dp2[x.fi] > cur + x.se){
                setdah.erase(mp(dp2[x.fi], x.fi));
                dp2[x.fi] = cur + x.se;
                setdah.insert(mp(dp2[x.fi], x.fi));
            }
        }
    }
    for (int i=1;i<=n;i++){
        qual[i] = (dp1[i] + dp2[i] == dp1[n]);
    }
    for (int i=1;i<=n;i++){
        if (!qual[i]) continue;
        for (auto x : adj[i]){
            if (!qual[x.fi]) continue;
            if (dp1[i] < dp1[x.fi]){
                if (dp1[i] + dp2[x.fi] + x.se == dp1[n]){
                    nadj[i].pb(x.fi);
                    in[x.fi]++;
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    preproc();

    int nodes = n + 1;
    int source = 1, sink = n;
    Dinic dinic(nodes, source, sink);
    for (int i = 1; i <= n; i++) {
        for (int j : nadj[i]) {
            dinic.add_edge(i, j, 1);
        }
    }
    cout << dinic.flow() << '\n';
    
    return 0;
}