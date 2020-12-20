/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Farras Faddila
 * Problem : B
 */
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const ll mod = 235813;
const int N = 1e5;
// KZATBRJP
 
ll fc[N + 5], ifc[N + 5];
 
ll fpow (ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) { ret = ret * a % mod; }
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
 
ll inv (ll a) {
    return fpow(a, mod - 2);
}
 
void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % mod;
    }
    ifc[N] = inv(fc[N]);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % mod;
    }
}
 
int n;
ll ar[N + 5], c[N + 5];
 
ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = fc[a];
    ret = ret * ifc[b] % mod;
    ret = ret * ifc[a - b] % mod;
    return ret;
}
 
int main() {
 
    // for (int i = 2; i < mod; i++) {
    //     if (mod % i == 0) {
    //         cout <<"DHFISUHF";
    //         return 0;
    //     }
    // }
 
    init_fac();
    cin >> n;
    for (int i = n - 1; i >= 0; i--) {
        cin >> ar[i];
        c[i] = C(n - 1, i);
    }
    ll temp = 0;
    ll sgn = 1;
    for (int i = 0; i < n; i++) {
        temp = (temp + (ar[i] * c[i] * sgn)) % mod;
        sgn *= -1;
    }
    temp %= mod;
    if (temp < 0) temp += mod;
    // cerr << "temp " << temp << '\n';
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll tanda = (i & 1 ? -1 : 1);
        ll cur = (temp - tanda * ar[i] * c[i]) % mod;
        if (cur < 0) cur += mod;
        ll need = (mod - cur) % mod;
        // cerr << need << '\n';
        ll lul = (need * tanda * inv(c[i])) % mod;
        if (lul < 0) lul += mod;
        ll cek = ar[i] % mod;
        if (cek < 0) cek += mod;
        if ((lul <= 100000 || lul >= mod - 100000) && (lul != cek)) {
            ans++;
        }
    }
    cout << ans << '\n';
}