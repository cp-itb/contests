/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Kamal Shafi
 * Problem : A - Kafe Programmer
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;

int n;
pair<ll, ll> ar[N];
priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }

    sort(ar + 1, ar + n + 1);

    ll tot = 0, cur_time = 0;
    int id = 1;
    
    while (id <= n){
        if (pq.empty()){
            cur_time = max(cur_time, ar[id].fi);
            pq.push(mp(ar[id].se, ar[id].fi));
            id++;
        }

        while (id <= n && cur_time >= ar[id].fi){
            pq.push(mp(ar[id].se, ar[id].fi));
            id++;
        }

        auto it = pq.top();
        cur_time += it.fi;
        tot += cur_time - it.se;
        // cout << it.fi << " " << cur_time << el;
        pq.pop();
    }
    while (!pq.empty()){
        auto it = pq.top();
        cur_time += it.fi;
        tot += cur_time - it.se;
        // cout << it.fi << " " << cur_time << el;
        pq.pop();
    }

    cout << tot / 3 << el;

    return 0;
}