/**
 * Contest : HPC 2020 Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : D
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

    map<vector<int>, int> dist;
    vector<int> s(7);
    for (int i = 0; i < 7; i++) {
        cin >> s[i];
    }

    auto revolve = [&](vector<int> v, int k, bool left) -> vector<int> {
        if (!left) {
            int cur = v[k - 1];
            v.erase(v.begin() + k - 1);
            v.insert(v.begin(), cur);
            return v;
        } else {
            int cur = v[0];
            v.erase(v.begin());
            v.insert(v.begin() + min(6, k - 1), cur);
            return v;
        }
    };

    dist[s] = 0;
    queue<vector<int>> q;
    q.emplace(s);
    while (!q.empty()) {
        vector<int> u = q.front();
        q.pop();
        for (int k = 2; k <= 7; k++) {
            for (int i = 0; i < 2; i++) {
                vector<int> v = revolve(u, k, i);
                if (dist.count(v)) continue;
                dist[v] = 1 + dist[u];
                q.emplace(v);
            }
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> v(7);
        for (int i = 0; i < 7; i++) {
            cin >> v[i];
        }
        cout << dist[v] << '\n';
    }

    return 0;
}