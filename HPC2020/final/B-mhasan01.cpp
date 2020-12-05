/**
 * Contest : HPC 2020 Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : B
 */
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));

    auto getId = [&](int x, int y) -> int {
        return m * x + y;
    };

    vector<int> par(n * m), sz(n * m);
    iota(par.begin(), par.end(), 0);
    fill(sz.begin(), sz.end(), 1);

    function<int(int)> fpar = [&](int x) {
        return (par[x] == x ? x : par[x] = fpar(par[x]));
    };

    auto merge = [&](int u, int v) -> void {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        sz[pu] += sz[pv];
        par[pv] = pu;
    };

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int ci = i + dx[k];
                int cj = j + dy[k];
                if (ci < 0 || ci >= n || cj < 0 || cj >= m) continue;
                if (v[ci][cj] != v[i][j]) continue;
                merge(getId(i, j), getId(ci, cj));
            }
        }
    }
    vector<int> euy;
    for (int i = 0; i < n * m; i++) {
        if (fpar(i) != i) continue;
        euy.emplace_back(sz[i]);
    }
    sort(euy.rbegin(), euy.rend());
    int len = euy.size();
    if (len <= 1) {
        cout << "TIDAK" << '\n';
        return 0;
    }
    int ans = n * m;
    int new_ans = euy[0] * euy[1];
    for (int i = 2; i < len; i++) {
        new_ans += euy[i];
    }
    if (new_ans > ans) {
        cout << "YA" << '\n';
        cout << new_ans << '\n';
    } else {
        cout << "TIDAK" << '\n';
    }

    return 0;
}