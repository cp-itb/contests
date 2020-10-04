/**
 * Contest : Techphoria 2020 - Qualification Trial
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : B
 */
#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

const int N = 1e6 + 5;

bitset<N> not_prime;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (not_prime[i] == 1) continue;
        for (int j = i + i; j < N; j += i) {
            not_prime[j] = 1;
        }
    }
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 2; i <= n; i++) {
        if (not_prime[i]) continue;
        v.emplace_back(i);
    }
    int len = v.size();
    for (int i = 0; i < len; i++) {
        cout << v[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}