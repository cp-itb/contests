/**
 * Contest : COMPFEST 2020 Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : E
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
const ll INF = 1e18;

int n, k;
ll a[N], d[N];
ll pc[N];
ll le[N], ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> d[i];
    }
    for (int i=1;i<=n;i++){
        pc[i] = a[i] + pc[i - 1];
    }
    if (k == 0){
        ll ans = 0;
        for (int i=1;i<=n;i++){
            ans = max(ans, pc[n] - pc[i - 1] - d[i]);
        }
        cout << ans << el;
        return 0;
    }
    if (k >= 2){
        ll tot = 0;
        for (int i=1;i<=n;i++){
            tot += a[i];
        }
        ll mn = INF;
        for (int i=1;i<n;i++){
            mn = min(mn, d[i]);
        }
        ll ans = max(max(0LL, tot - mn), a[n] - d[n]);
        cout << ans << el;
        return 0;
    }
    if (k == 1){
        fill(le, le + N, INF);
        for (int i=1;i<=n;i++){
            le[i] = min(le[i - 1], d[i]);
        }
        fill(ri, ri + N, 0);
        ll ans = 0;
        set<pair<ll, int>> setdah;
        for (int i=n;i>=1;i--){
            ri[i] = max(ri[i + 1], pc[n] - pc[i - 1] - d[i]);
            setdah.insert(mp(pc[n] - pc[i - 1] - d[i], i));
        }
        setdah.erase(mp(pc[n] - pc[n - 1] - d[n], n));
        for (int i=n - 1;i>=2;i--){
            ans = max(ans, ri[i]);
            setdah.erase(mp(pc[n] - pc[i - 1] - d[i], i));
            ans = max(ans, setdah.rbegin()->fi - a[i] + max(0LL, a[i] - d[i]));
        }
        // setdah.clear();
        // for (int i=1;i<n;i++){
        //     setdah.insert(mp(pc[n] - pc[i - 1] - d[i], i));
        // }
        ll mx = 0, kur = 0;
        for (int i=n - 1;i>=2;i--){
            mx = max(mx, pc[n] - pc[i] - d[i + 1]);
            // kur += a[i];
            // setdah.erase(mp(pc[n] - pc[i - 1] - d[i], i));
            ans = max(ans, mx + max(0LL, pc[i] - le[i]));//max(max(0LL, pc[i] - d[i]), setdah.rbegin()->fi - kur));
        }
        cout << ans << el;
    }

    return 0;
}