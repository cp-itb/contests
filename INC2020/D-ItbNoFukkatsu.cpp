/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Hasan
 * Problem  : D
 */
// belum di test, harusnya bener tapi dah habis waktu :(
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
#ifdef LOCALE
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

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

using pll = pair<long long, long long>;

struct vertex {
    pll val;
    vertex *l, *r;
    vertex(pll val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(make_pair(0LL, 0LL)), l(l), r(r) {
        if (l) {
            val.first += l->val.first;
            val.second += l->val.second;
        }
        if (r) {
            val.first += r->val.first;
            val.second += r->val.second;
        }
    }
};
typedef vertex* pvertex;

const int N = 2e5 + 5;

int n, q;
int cnt[N];
pvertex psegtree[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(make_pair(0LL, 0LL));
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos, pll val) {
    if (s == e && s == pos)
        return new vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos, val));
}

pll getQuery(pvertex v, pvertex w, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return make_pair(0, 0);
    if (l <= s && e <= r)
        return make_pair(w->val.first - v->val.first, w->val.second - v->val.second);
    int mid = (s + e) >> 1;
    pll p1 = getQuery(v->l, w->l, s, mid, l, r);
    pll p2 = getQuery(v->r, w->r, mid + 1, e, l, r);
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}

int getIdx(pvertex v, pvertex w, int s, int e, int cur) {
    if (cur < 0) return -1;
    if (s == e)
        return s;
    int mid = (s + e) >> 1;
    int curval = (w->l->val.first - v->l->val.first);
    if (curval > cur)
        return getIdx(v->l, w->l, s, mid, cur);
    else
        return getIdx(v->r, w->r, mid + 1, e, cur - curval);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n);
    psegtree[0] = build(1, N);
    for (int i = 1; i <= n; i++) {
        int x; in(x);
        cnt[x]++;
        long long res = (1LL) * x * cnt[x];
        psegtree[i] = update(psegtree[i - 1], 1, N, x, make_pair(cnt[x], res));
    }

    auto can = [&](int L, int R, int A, int B, int S, int len) -> bool {
        int l = A, r = B;
        int res = getQuery(psegtree[L - 1], psegtree[R], 1, N, 1, B).first;
        int cur = res - len;
        int at = getIdx(psegtree[L - 1], psegtree[R], 1, N, cur);
        debug() << imie(L) imie(R) imie(A) imie(B) imie(S);
        debug() << imie(at);
        if (at < A) return false;
        pll curs = getQuery(psegtree[L - 1], psegtree[R], 1, N, at, B);
        long long resCnt = curs.first;
        long long sum = curs.second;
        sum -= (1LL) * (resCnt - len) * at;
        debug() << imie(resCnt) imie(len) imie(at) imie(sum);
        return (sum >= (1LL) * len * S);
    };

    in(q);
    while (q--) {
        int L, R, A, B, S;
        in(L), in(R), in(A), in(B), in(S);
        debug() << imie(q);
        int l = 1, r = R - L + 1, at = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(L, R, A, B, S, mid)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        out(at, '\n');
    }

    return 0;
}