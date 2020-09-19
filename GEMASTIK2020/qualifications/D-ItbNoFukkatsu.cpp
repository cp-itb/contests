/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : D
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

int n, m;
int ar[N];
vector<int> adj[N];
int in[N], dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        in[b]++;
    }
    fill(dp, dp + n, 0);
    queue<int> qu;
    int ans = 0;
    for (int i=0;i<n;i++){
        if (in[i] == 0){
            dp[i] = ar[i];
            qu.push(i);
        }
    }
    while (!qu.empty()){
        int node = qu.front();
        qu.pop();
        ans = max(ans, dp[node]);
        for (auto x : adj[node]){
            dp[x] = max(dp[x], dp[node] + ar[x]);
            if (--in[x] == 0){
                qu.push(x);
            }
        }
    }
    cout << ans << el;

    return 0;
}