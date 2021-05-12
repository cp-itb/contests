 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Farras Faddila
  * Problem : D
  */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int K = 1e5;
pair<ll, ll> pos[K + 5];

ll count(pair<ll, ll> a, pair<ll, ll> b) {
    if (a == b) return 1;
    ll fpb = __gcd(abs(a.first - b.first), abs(a.second - b.second));
    return fpb + 1;
}

bool segaris(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    return (a.second - b.second) * (a.first - c.first) == (a.second - c.second) * (a.first - b.first);
}

bool urut(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    if (a.first == b.first && a.first == c.first) {
        return (((a.second <= b.second) && (b.second <= c.second)) || ((a.second >= b.second) && (b.second >= c.second)));
    }
    return ((a.first <= b.first && b.first <= c.first) || (a.first >= b.first && b.first >= c.first));
}

ll n, m, k;

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        ll x;
        cin >> x;
        pos[i] = {(x - 1) / m, (x - 1) % m};
    }
    ll ans = count(pos[1], pos[2]);
    for (int i = 3; i <= k; i++) {
        if (!segaris(pos[i - 2], pos[i - 1], pos[i])){
            ans += (count(pos[i - 1], pos[i]) - 1); 
        } else {
            if (urut(pos[i - 2], pos[i - 1], pos[i])) {
                ans += (count(pos[i - 1], pos[i]) - 1);
            } else if (urut(pos[i], pos[i - 2], pos[i - 1])) {
                ans += (count(pos[i - 2], pos[i]) - 1);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}