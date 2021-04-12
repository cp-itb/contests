#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 60;
const ll INF = 1e9;
ll n, k, tot;
ll a[N + 5];

void go(int c, ll mul, int pc) {
    if (c == n) {
        int u = (pc & 1 ? -1 : 1);
        tot += u * ((k - 1) / mul);
        return;
    }
    if (mul * a[c] <= INF) {
        go(c + 1, mul * a[c], pc + 1);
    }
    go(c + 1, mul, pc);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    tot = 0;
    go (0, 1, 0);
    ll ans = k - tot;
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