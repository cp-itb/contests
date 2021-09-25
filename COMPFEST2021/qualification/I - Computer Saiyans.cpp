/**
 * Contest : Compfest 13 Qualification
 * Team    : Computer Saiyans
 * Author  : Jauhar Wibisono
 * Problem : Inilah Suasana Pemilihan Mahkota Hutan
 */

#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
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
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
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
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
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
            q.push(s);
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

const long long INF = 1e18+4;
const int maxn = 1e5+4, maxe = 102;
int n;
int v[maxn];
int cnt[2][maxe];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> v[i];
    memset(cnt, 0, sizeof cnt);
    for (int i=0; i<n; i++){
        int e;
        cin >> e;
        cnt[v[i]][e]++;
    }
    Dinic mf(404, 0, 401);
    // source = 0, sink = 401
    // pasang edge dari source ke v = 0
    for (int i=1; i<=100; i++) mf.add_edge(0, i, INF);
    // pasang edge internal v = 0
    for (int i=1; i<=100; i++) mf.add_edge(i, i+100, cnt[0][i]);
    // pasang edge antara v = 0 dan v = 1
    for (int i=1; i<=100; i++){
        for (int j=1; j<=100; j++){
            if (__gcd(i, j) > 1) mf.add_edge(100+i, 200+j, INF);
        }
    }
    // pasang edge internal v = 1
    for (int i=1; i<=100; i++) mf.add_edge(i+200, i+300, cnt[1][i]);
    // pasang edge dari v = 1 ke sink
    for (int i=301; i<=400; i++) mf.add_edge(i, 401, INF);
    // for (int i=0; i<=401; i++){
    //     cout << i << ": ";
    //     for (int u : mf.adj[i]) cout << u << ' ';
    //     cout << '\n';
    // }
    // for (auto e : mf.edges){
    //     cout << e.v << ' ' << e.u << '\n';
    // }
    cout << mf.flow() << '\n';
    return 0;
}