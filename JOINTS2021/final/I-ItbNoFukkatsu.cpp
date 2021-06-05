 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Kamal Shafi
  * Problem : I
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
const int MX = 10;
const int INF = 1e9;

int n, m, money, s; // node, edge, money, start node;
vector<int> target;
vector<pii> adj[N];

int dist[MX][N];
void dijkstra(int sc, int id){
    fill(dist[id], dist[id] + n + 2, INF);
    dist[id][sc] = 0;
    set<pii> setdah;
    setdah.insert(mp(0, sc));
    while (!setdah.empty()){
        int node = setdah.begin()->se;
        int cur = setdah.begin()->fi;
        setdah.erase(mp(cur, node));
        for (auto& x : adj[node]){
            if (dist[id][x.fi] > cur + x.se){
                setdah.erase(mp(dist[id][x.fi], x.fi));
                dist[id][x.fi] = cur + x.se;
                setdah.insert(mp(dist[id][x.fi], x.fi));
            }
        }
    }
}
int cost[MX][MX];

int dp[(1 << MX)][MX];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> money >> s;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        if (c == 'Y'){
            target.pb(i);
        }
    }
    for (int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    int len = target.size();
    for (int i=0;i<len;i++){
        dijkstra(target[i], i);
    }
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            cost[i][j] = dist[i][target[j]];
        }
    }
    for (int i=0;i<(1 << MX);i++){
        for (int j=0;j<MX;j++){
            dp[i][j] = INF;
        }
    }
    for (int i=0;i<len;i++){
        dp[(1 << i)][i] = dist[i][s];
    }
    for (int i=1;i<(1 << len);i++){
        for (int last=0;last<len;last++){
            if (dp[i][last] == INF) continue;
            for (int next=0;next<len;next++){
                if (i & (1 << next)) continue;
                int ni = (i | (1 << next));
                dp[ni][next] = min(dp[ni][next], dp[i][last] + cost[last][next]);
            }
        }
    }
    pii ans = mp(0, money);
    for (int i=0;i<(1 << len);i++){
        int bitCnt = __builtin_popcount(i);
        for (int last=0;last<len;last++){
            if (dp[i][last] <= money){
                ans = max(ans, mp(bitCnt, money - dp[i][last]));
            }
        }
    }
    if (ans.fi == 0){
        cout << "Gama tidak terselamatkan" << el;
        return 0;
    }
    cout << ans.fi << " " << ans.se << el;

    return 0;
}