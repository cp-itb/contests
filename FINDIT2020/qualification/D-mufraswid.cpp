/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Morgen Sudyanto, Jun Ho Choi Hedyatmo
 * Problem : D - Musim Hujan
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;
vector<pii> adj[10005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        char a[n+5][n+5];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cin >> a[i][j];
            }
        }
        for (int i=1;i<=n*n;i++) adj[i].clear();
        int x[n+5][n+5];
        int cnt = 1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                x[i][j] = cnt++;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (i+1 >= 1 && i+1 <= n && j >= 1 && j <= n) {
                    if (a[i][j] != a[i+1][j]) adj[x[i][j]].pb({x[i+1][j], 1}); else adj[x[i][j]].pb({x[i+1][j], 0});
                }
                if (i-1 >= 1 && i-1 <= n && j >= 1 && j <= n) {
                    if (a[i][j] != a[i-1][j]) adj[x[i][j]].pb({x[i-1][j], 1}); else adj[x[i][j]].pb({x[i-1][j], 0});
                }
                if (i >= 1 && i <= n && j+1 >= 1 && j+1 <= n) {
                    if (a[i][j] != a[i][j+1]) adj[x[i][j]].pb({x[i][j+1], 1}); else adj[x[i][j]].pb({x[i][j+1], 0});
                }
                if (i >= 1 && i <= n && j-1 >= 1 && j-1 <= n) {
                    if (a[i][j] != a[i][j-1]) adj[x[i][j]].pb({x[i][j-1], 1}); else adj[x[i][j]].pb({x[i][j-1], 0});
                }
            }
        }
        int s,t;
        cin >> s >> t;
        int vis[n*n+5];
        for (int i=1;i<=n*n+3;i++) vis[i] = 123456789;
        deque<int> p;
        vis[s] = 0;
        p.push_front(s);
        while (!p.empty()) {
            int cur = p.front();
            p.pop_front();
            for (int i=0;i<adj[cur].size();i++) {
                int next = adj[cur][i].fi;
                int w = adj[cur][i].se;
                if ((vis[cur] + w) < vis[next]) {
                    vis[next] = vis[cur] + w;
                    if (w == 0) p.push_front(next);
                    else p.push_back(next);
                }
            }
        }
        cout << vis[t] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}