/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Hasan
 * Problem  : A
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

const int N = 15;

int n;
int a[N][N];

int checkRow(int i) {
    int cur = -1;
    int res = 0;
    for (int j = 1; j <= n; j++) {
        if (a[i][j] > cur) {
            cur = a[i][j];
            ++res;
        }
    }
    return res;
}

int checkCol(int j) {
    int cur = -1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i][j] > cur) {
            cur = a[i][j];
            ++res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << checkCol(i) << (i == n ? '\n' : ' ');
    }
    for (int i = 1; i <= n; i++) {
        cout << checkRow(i) << '\n';
    }

    return 0;
}