/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Emeurgence
* Author  : Muhammad Kamal Shafi
* Problem : E - Wifi Network
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
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

const int N = 1e5 + 10;
const ll INF = 1e18;
const int INT_INF = 1e9;

int n;
int q;
pll ar[N];
pll pos[2];

vector<pll> vec;
vector<ll> da, db;

ll find_edist(pll a, pll b){
    ll delx = abs(a.fi - b.fi);
    ll dely = abs(a.se - b.se);
    return delx * delx + dely * dely;
}

set<pli> setid;

vector<ll> t[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v].pb(vec[tl - 1].se);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
    merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
}

int ask(int v, int tl, int tr, int l, int r, ll mx){
    if (l > r || tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r){
        if (t[v][0] > mx) return 0;
        int low = 0, high = (int)t[v].size() - 1;
        while (low < high){
            int mid = (low + high + 1) / 2;
            if (t[v][mid] <= mx){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        return low + 1;
    }
    int tm = (tl + tr) / 2;
    return ask(v * 2, tl, tm, l, r, mx) + ask(v * 2 + 1, tm + 1, tr, l, r, mx);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    for (int i=0;i<2;i++){
        cin >> pos[i].fi >> pos[i].se;
    }

    for (int i=1;i<=n;i++){
        ll cura = find_edist(ar[i], pos[0]);
        ll curb = find_edist(ar[i], pos[1]);
        pll cur = mp(cura, curb);
        vec.pb(cur);
        da.pb(cura);
        db.pb(curb);
    }
    sort(vec.begin(), vec.end());
    sort(da.begin(), da.end());
    sort(db.begin(), db.end());

    int tempid = 0;
    setid.insert(mp(-1LL, 0LL)); // dummy
    for (auto& x : vec){
        pli temp = mp(x.fi, ++tempid);
        setid.insert(temp);
        x.fi = temp.se;
    }
    build(1, 1, n);
    cin >> q;
    while (q--){
        ll r[2];
        for (int i=0;i<2;i++){
            ll a;
            cin >> a;
            r[i] = a * a; // kuadrat jarak
        }
        auto id = setid.upper_bound(mp(r[0], INT_INF));
        id--;
        int ri = id->se;

        int ans = 0;
        if (r[0] >= da[0]){
            int low = 0, high = n - 1;
            while (low < high){
                int mid = (low + high + 1) / 2;
                if (da[mid] <= r[0]){
                    low = mid;
                } else{
                    high = mid - 1;
                }
            }
            ans += low + 1;
        }
        if (r[1] >= db[0]){
            int low = 0, high = n - 1;
            while (low < high){
                int mid = (low + high + 1) / 2;
                if (db[mid] <= r[1]){
                    low = mid;
                } else{
                    high = mid - 1;
                }
            }
            ans += low + 1;
        }
        // cout << ans << el;
        ans -= 2 * ask(1, 1, n, 1, ri, r[1]);
        cout << n - ans << el;
    }

    return 0;
}