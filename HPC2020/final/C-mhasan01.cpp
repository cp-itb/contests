/**
 * Contest : HPC 2020 Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : C
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

    int tc;
    cin >> tc;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (tc--) {
        char c;
        cin >> c;
        if (c == 'A') {
            int x, y;
            cin >> x >> y;
            for (int i = 0; i < y; i++) {
                pq.emplace(x);
            }
        } else {
            int x;
            cin >> x;
            for (int i = 0; i < x; i++) {
                cout << pq.top() << (i == x - 1 ? '\n' : ' ');
                pq.pop();
            }
        }
    }

    return 0;
}