/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Farras Faddila
 * Problem : G
 */
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 1e5;
const ll mod = 998244353;
 
int n;
int p[N + 10];
bool vis[N + 10];
int gpf[N + 10];
 
ll fpow(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) {ret = ret * a % m;}
        a = a * a % m;
        b >>= 1;
    }
    ret = ret % m;
    if (ret < 0) ret += m;
    return ret;
}
 
void sieve() {
    for (int i = 2; i <= N; i++) {
        if (gpf[i]) continue;
        for (int j = i; j <= N; j += i) {
            gpf[j] = i;
        }
    }
}
 
ll order(ll a) {
    // hitung order mod 2, prekondisi a harus ganjil
    assert (a & 1);
 
    if (a == 1) return 1;
 
    ll na = a;
    ll phi = a;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            phi -= phi / i;
            while (a % i == 0) {
                a /= i;
            }
        }
    }
    if (a > 1) {
        phi -= phi / a;
    }
 
    // cerr << phi << ' ' << a << '\n';
 
    vector<ll> divs; 
    for (ll i = 1; i * i <= phi; i++) {
        if (phi % i == 0) {
            divs.emplace_back(i);
            if (i != (phi / i))
                divs.emplace_back(phi / i);
        }
    }
    sort(divs.begin(), divs.end());
    // for (auto i : divs) {
    //     cerr << i << ' ';
    // }
    // cerr << '\n';
    for (int i = 0; i < (int)divs.size(); i++) {
        // cerr << fpow(2LL, divs[i], a) << ' ' << divs[i] << '\n';
        if (fpow(2LL, divs[i], na) == 1) {
            return divs[i];
        }
    }
    return -1;
}
 
ll lcm (const vector<ll>& V) {
    map<ll, ll> mp;
    ll ret = 1;
    for (auto el : V) {
        while (el > 1) {
            ll prime = gpf[el];
            ll cnt = 0;
            while (el % prime == 0) {
                el /= prime;
                cnt++;
            }
            mp[prime] = max(mp[prime], cnt);
        }
    }
    for (auto el : mp) {
        ret = (ret * fpow(el.first, el.second, mod)) % mod;
    }
    return ret;
}
 
int main() {
    sieve();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<ll> ve;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cur = i, cnt = 1;
        vis[cur] = 1;
        while (p[cur] != i) {
            cur = p[cur];
            vis[cur] = 1;
            cnt++;
        }
        ve.push_back(cnt);
    }
 
    ll A = 0;
    vector<ll> orders;
    for (auto& el : ve) {
        ll pw = 0;
        while (el % 2 == 0) {
            el /= 2, pw++;
        }
        ll a = pw, b = el;
        assert(b & 1);
        ll ord_b = order(b);
        A = max(A, a);
        orders.emplace_back(ord_b);
    }
    ll ans = (A + lcm(orders)) % mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
 
    // for (int i = 1; i <= 20; i += 2) {
    //     cout << "order " << i << " : " << order(i) << '\n';
    // }
    // cout << order(9) << '\n';
}