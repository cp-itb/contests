/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Hasan
 * Problem  : A
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

const int N = 105;
const long long INF = 2e9;

struct st {
    string x, y;
    long long a, b, c, d;
    int r1, r2;
    bool operator<(const st& o) {
        long long dx1 = a - c, dx2 = o.a - o.c; 
        long long dy1 = b - d, dy2 = o.b - o.d;
        return (dx1 * dx1 + dy1 * dy1 > dx2 * dx2 + dy2 * dy2);
    };
    long long F() {
        long long dx = a - c;
        long long dy = b - d;
        return dx * dx + dy * dy;
    }
};

long long G(long long x) {
    long long l = 1, r = INF, ret = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (mid * mid <= x) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ret;
}

int n;
st p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].a >> p[i].b >> p[i].r1;
        cin >> p[i].y >> p[i].c >> p[i].d >> p[i].r2;
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        long long res = p[i].F();
        cout << p[i].x << " " << p[i].y << " " << G(res) << '\n';
    }

    return 0;
}