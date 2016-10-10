/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Willy
 * Problem : G - Beautiful Triple
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#ifdef DEBUG
    #include <ctime>
#endif
using namespace std;

// template

// abbreviations

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;
#define a first
#define b second
#define que queue
#define pque priority_queue
#define stk stack
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define pu push
#define po pop
#define mp make_pair
#define it iterator
#define sz(var) ((int) var.size())
#define rep(it, n) for(int it = 0; it < n; ++it)
#define dep(it, n) for(int it = n - 1; it >= 0; --it)
#define rep1(it, n) for(int it = 1; it <= n; ++it)
#define dep1(it, n) for(int it = n; it > 0; --it)
#define loop(it, from, to) for(int it = (from); it <= (to); ++it)
#define iter(it, cont) for(__typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); ++it)
#define riter(it, cont) for(__typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); ++it)
#define all(cont) (cont).begin(), (cont).end()
#define rng(cont, n) cont, cont + n
#define memclr(var) memset(var, 0, sizeof(var))

const int INF = INT_MAX;
const int NINF = INT_MIN;
const ll INF_LL = LLONG_MAX;
const ll NINF_LL = LLONG_MIN;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;

inline ll pos_m(ll a, ll c = MOD) { while (a < 0) { a += c; } return a; }
inline ll add_m(ll a, ll b, ll c = MOD) { return (a + b) % c; }
inline ll mul_m(ll a, ll b, ll c = MOD) { return (a * b) % c; }
inline ll sub_m(ll a, ll b, ll c = MOD) { return pos_m((a - b) % c, c); }

#ifdef DEBUG
    #define debug(fmt, args...) printf("Line %d, in %s\t: " fmt, __LINE__, __FUNCTION__, ##args)
    #define rep_rt() printf("[Run time: %.3fs]\n", ((double) clock()) / CLOCKS_PER_SEC)
#else
    #define debug(...)
#endif

// end of template

#define MAXA (int) (1e5)
vi pos[MAXA + 1];
#define MAXN (int) (1e5)
int arr[MAXN + 1];

int main() {
#ifdef DEBUG
    freopen("G.in", "r", stdin);
#endif
    
    int nt;
    scanf("%d", &nt);
    rep1(t, nt) {
        int n;
        scanf("%d", &n);
        rep1(a, MAXA) {
            pos[a].clear();
        }
        rep(idx, n) {
            scanf("%d", arr + idx);
            pos[arr[idx]].pub(idx);
        }
        ll ans = 0;
        rep1(a, MAXA) {
            if (sz(pos[a]) <= 1)
                continue;
            ll tot = pos[a].back() - pos[a][0];
            rep1(idx, sz(pos[a]) - 1) {
                tot = add_m(tot, (pos[a].back() - pos[a][0] - 1) - (pos[a][idx] - pos[a][0]));
            }
            for (int idx = sz(pos[a]) - 1; idx > 0; --idx) {
                ans = add_m(ans, tot);
                tot = sub_m(tot, mul_m(idx, pos[a][idx] - pos[a][idx - 1]) - 1);
            }
        }
        printf("Case #%d: %lld\n", t, ans);
    }

#ifdef DEBUG
    rep_rt();
#endif
    return 0;
}