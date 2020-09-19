/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : I
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

const int N = 1e5 + 10;

int n, m, k;
bool bad[N];
int par[N], sz[N];

vector<pair<int, pii>> edges;

int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        par[i] = i;
        sz[i] = 1;
    }
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
    }
    for (int i=1;i<=m;i++){
        int a;
        cin >> a;
        bad[a] = 1;
    }
    int ans = 0;
    for (int i=0;i<k;i++){
        int a, b, w;
        cin >> a >> b >> w;
        if (bad[a] != bad[b]) continue;
        else{
            edges.pb(mp(w, mp(a, b)));
        }
    }
    sort(edges.begin(), edges.end());
    for (auto x : edges){
        int w = x.fi;
        auto edge = x.se;
        if (find(edge.fi) == find(edge.se)) continue;
        ans += w;
        make(edge.fi, edge.se);
    }
    cout << ans << el;

    return 0;
}