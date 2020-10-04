/**
 * Contest : Techphoria 2020 - Qualification Trial
 * Team    : Chapter3
 * Author  : Muhammad Kamal Shafi
 * Problem : C
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
const ll INF = 1e18, MX = 1e12;

int q;
int n;
vector<pair<int, ll>> adj[N];
vector<ll> ans;

void init(){
    ans.clear();
    for (int i=1;i<N;i++){
        adj[i].clear();
    }
}
void dfs_solve(int node, ll cur_time, ll fac){
    if (adj[node].empty()){
        ans.pb(cur_time);
        return;
    }
    // if (fac > MX || cur_time > MX) return;
    ll mn = INF;
    for (auto x : adj[node]){
        mn = min(mn, x.se);
    }
    for (auto x : adj[node]){
        if (x.se == mn){
            dfs_solve(x.fi, cur_time + x.se * fac, fac);
        } else{
            dfs_solve(x.fi, cur_time + mn * fac + (x.se - mn) * 2LL, fac);
        }
    }
}

void solve(){
    cin >> n;
    init();
    for (int i=2;i<=n;i++){
        int p;
        ll d;
        cin >> p >> d;
        adj[p].pb(mp(i, d));
    }
    dfs_solve(1, 0, 1);
    sort(ans.begin(), ans.end());
    ans.pb(INF);
    int q;
    cin >> q;
    while (q--){
        ll x;
        cin >> x;
        cout << int(upper_bound(ans.begin(), ans.end(), x) - ans.begin()) << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}