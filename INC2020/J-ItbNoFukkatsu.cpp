/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : J
 */
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
const int M = 1e5 + 10;
const int MX = 2e5;
const int sqr = sqrt(MX) + 1;

int n, m;
ll ar[N];

bool is_upd[N];

vector<int> adj[N], out[N];
ll ans[N];
ll sum[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        int c;
        cin >> c;
        if (c > sqr){
            is_upd[i] = 1;
        }

        ll sumsq = 0;
        for (int j=0;j<c;j++){
            int gen_id;
            cin >> gen_id;
            sum[i] += ar[gen_id];
            sumsq += ar[gen_id] * ar[gen_id];
            adj[i].pb(gen_id);
            if (is_upd[i]){
                out[gen_id].pb(i);
            }
        }
        ans[i] = (sum[i] * sum[i] - sumsq) / 2;

    }
    int q;
    cin >> q;
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 2){
            int id;
            cin >> id;
            if (is_upd[id]){
                cout << ans[id] << el;
            } else{
                ll sumsq = 0;
                ll sum = 0;
                for (auto x : adj[id]){
                    sumsq += ar[x] * ar[x];
                    sum += ar[x];
                }
                cout << (sum * sum - sumsq) / 2 << el;
            }
        } else{
            int id;
            ll nval;
            cin >> id >> nval;

            for (auto x : out[id]){
                ll kec = sum[x] - ar[id];
                ans[x] = ans[x] - ar[id] * kec + nval * kec;
                sum[x] += nval - ar[id];
            }
            ar[id] = nval;
        }
    }

    return 0;
}