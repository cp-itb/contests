/**
 * Contest : HPC 2020 Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : E
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

const int N = 1e5 + 5;

long long pre[N];

int phi(int x) {
    int ret = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ret -= (ret / i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) ret -= (ret / x);
    return ret;
}

int get(int x) {
    int ret = 1;
    while (x > 1) {
        x = phi(x);
        ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[1] = 1;
    for (int i = 2; i < N; i++) {
        pre[i] = pre[i - 1] + get(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }

    return 0;
}