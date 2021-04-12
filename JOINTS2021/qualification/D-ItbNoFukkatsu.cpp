/**
  * Contest : Joints 2021 Qualification
  * Team    : ItbNoFukkatsu
  * Author  : Farras Faddila
  * Problem : D
***/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int ar[N + 5];
int n;
vector<int> par, sz, ans;

vector<int> prime_factors(int x) {
    vector<int> ret;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ret.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ret.push_back(x);
    return ret;
}

void init(int x) {
    par.resize(x);
    sz.resize(x);
    ans.resize(x);
    for (int i = 0; i < x; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int fpar(int x) {
    return par[x] == x ? x : par[x] = fpar(par[x]);
}

void merge(int x, int y) {
    x = fpar(x), y = fpar(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
}

void solve() {
    cin >> n;

    vector<vector<int>> primes(n);
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] == 1) continue;
        primes[i] = prime_factors(ar[i]);
        for (auto e : primes[i]) {
            if (mp.find(e) == mp.end()) {
                mp[e] = cnt++;
            }
        }
    }

    init(cnt);

    for (int i = 0; i < n; i++) {
        if (ar[i] == 1) continue;
        int len = (int) primes[i].size();
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < j; k++) {
                merge(mp[primes[i][j]], mp[primes[i][k]]);
            }
        }
    }

    int jar = 0;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (ar[i] == 1) {
            jar++;
            mx = max(mx, 1);
            continue;
        }
        ans[fpar(mp[primes[i][0]])]++;
    }
    for (auto i : mp) {
        if (par[i.second] != i.second) continue;
        jar++;
        mx = max(mx, ans[i.second]);
    }

    cout << jar << ' ' << mx << '\n';
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