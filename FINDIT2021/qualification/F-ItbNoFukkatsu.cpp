/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : To The Top
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

const int H = 60;

ll m, x, h, s; // tengah, aritmatik prog, banyak anak tangga, stamina

ll aritmethic(ll a, ll x, ll n){
    return (a + a + x * (n - 1)) * n / 2LL;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> x >> h >> s;
    ll ans = 0;
    ll cur = m - x;
    for (ll i=1;i<=h;i++){
        cur += x * (h - i + 1);
        ans += cur;
    }
    ans = s - ans;
    if (ans >= 0){
        cout << "YA " << ans << el;
    } else{
        cout << "TIDAK " << -ans << el;
    }

    return 0;
}