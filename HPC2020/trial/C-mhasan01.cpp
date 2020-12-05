/**
 * Contest : HPC 2020 Trial
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

const int N = 1e5 + 5;
const int INF = 2e9;

int n;
int a[N];
int pre[N], suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = a[i] + suf[i + 1];
    }
    int ans = INF;
    int pos = -1;
    for (int i = 0; i <= n; i++) {
        int cur = abs(pre[i] - suf[i + 1]);
        if (ans > cur) {
            ans = cur;
            pos = i;
        }
    }
    cout << pos << '\n';

    return 0;
}