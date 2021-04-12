/**
  * Contest : Joints 2021 Qualification
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Kamal Shafi
  * Problem : H
***/
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
const int INF = 1e9;

int n, m;
int ar[N];
vector<int> adj[N];
int deg[N];
int s, e;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        deg[b]++;
    }
    cin >> s >> e;
    queue<int> qu;
    for (int i=1;i<=n;i++){
        if (deg[i] == 0){
            qu.push(i);
        }
    }
    vector<int> dp(n + 1, -INF);
    dp[s] = 0;

    while (!qu.empty()){
        int node = qu.front();
        qu.pop();
        for (auto &x : adj[node]){
            dp[x] = max(dp[x], dp[node] + ar[node]);
            if (--deg[x] == 0){
                qu.push(x);
            }
        }
    }
    if (dp[e] < 0 || dp[e] <= ar[e]){
        cout << "TIDAK" << el;
    } else{
        cout << "YA " << dp[e] << el;
    }

    return 0;
}