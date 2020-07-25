/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Emeurgence
* Author  : Muhammad Kamal Shafi
* Problem : B - Shopee Logistics
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
using pil = pair<int, ll>;

const int N = 1e5 + 10;

int n;
vector<pil> adj[N];

pil dfs_furthest(int node, int p, ll cur){
    pil ret = mp(node, cur);
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        pil temp = dfs_furthest(x.fi, node, cur + x.se);
        if (temp.se > ret.se){
            ret = temp;
        }
    }
    return ret;
}

ll most;
pil dfs2(int node, int p, ll cur){
    pil ret = mp(node, cur);
    for (auto x : adj[node]){
        if (x.fi == p || cur + x.se >= most) continue;
        pil temp = dfs2(x.fi, node, cur + x.se);
        if (temp.se > ret.se){
            ret = temp;
        }
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    pil tempa = dfs_furthest(1, 1, 0);
    pil tempb = dfs_furthest(tempa.fi, tempa.fi, 0);
    most = tempb.se;

    pil temp1 = dfs2(tempa.fi, tempa.fi, 0);
    pil temp2 = dfs2(tempb.fi, tempb.fi, 0);
    cout << max(temp1.se, temp2.se) << el;

    return 0;
}