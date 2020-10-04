/**
 * Contest : Techphoria 2020 - Qualification
 * Team    : Chapter3
 * Author  : Farras Hibban, Muhammad Kamal Shafi
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

ll a, b, n, p;
string s;
vector<ll> pw10;

void init(){
    s.clear();  
    {
        ll temp = a / b;
        a %= b;
    }
    while (s.size() < n){
        a *= 10LL;
        ll temp = a / b;
        a %= b;
        s.pb(char(temp + '0'));
    }
    while (s.size() > n) s.pop_back();
    // cerr << s << el;

    ll ans = 0;

    pw10.clear(), pw10.resize(n + 1);

    ll lol = 1;
    for(int i = 0; i <= n; i++) {
        pw10[i] = lol;
        lol = lol * 10 % p;
    }

    if(p == 2 || p == 5) {
        for(int i = 0; i < n; i++) {
            int dig = (int) s[i] - '0';
            // cerr << dig << ' ' << i << '\n';
            if(dig % p == 0) {
                ans += (i + 1);
            }
        }
    } else {
        vector<ll> cnt(p, 0);
        ll temp = 0;
        cnt[temp]++;
        for(int i = 0; i < n; i++) {
            temp = (temp * 10 + (s[i] - '0')) % p;
            ll cur = (temp * pw10[n - 1 - i]) % p;
            cnt[cur]++;
        }
        for(int i = 0; i < p; i++) {
            ans += cnt[i] * (cnt[i] - 1) / 2;
        }
    }

    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--){
        cin >> a >> b >> n >> p;
        init();
    }

    return 0;
}