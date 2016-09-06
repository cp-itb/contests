/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : hehehe
 * Author  : Willy
 * Problem : C - Menyelamatkan Mbak Miku
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
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define ii pair<int, int>
#define a first
#define b second
#define vii vector<ii>
#define mii map<ii>
#define vvi vector<vi>
#define vvl vector<vl>
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

typedef unsigned long long ull;
typedef long long ll;

const int INF = INT_MAX;
const int NINF = INT_MIN;
const ll INF_LL = LLONG_MAX;
const ll NINF_LL = LLONG_MIN;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;

#ifdef DEBUG
    #define debug(fmt, args...) printf("Line %d, in %s\t: " fmt, __LINE__, __FUNCTION__, ##args)
    #define rep_rt() printf("[Run time: %.3fs]\n", ((double) clock()) / CLOCKS_PER_SEC)
#else
    #define debug(...)
#endif

// end of template

bool is_rb(ii a, ii b) {
    if ((a.a <= b.a) and (a.b <= b.b))
        return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("C.in", "r", stdin);
#endif

    int nt;
    scanf("%d", &nt);
    while (nt--) {
        int r, c;
        ll k, h;
        scanf("%d %d %lld %lld", &r, &c, &k, &h);
        ll lr = r, lc = c;
        vector<vi> matx(r + 1, vi(c + 1));
        vector<ii> loc_dict(r * c + 1);
        rep1(i, r) {
            rep1(j, c) {
                ll li = i, lj = j;
                matx[i][j] = ((((li - 1) * lc + lj) * k + h) % (lr * lc)) + 1;
                loc_dict[matx[i][j]] = mp(i, j);
            }
        }
        vi ans(r + c, 0);
        if ((r == 1) or (c == 1)) {
            rep1(i, r) {
                rep1(j, c) {
                    ans[(i - 1) * c + j] = matx[i][j];
                }
            }
        } else {
            set<int> ans_ex;
            ans[1] = matx[1][1];
            ans[r + c - 1] = matx[r][c];
            ans_ex.insert(1);
            ans_ex.insert(r + c - 1);
            rep1(val, r * c) {
                ii loc = loc_dict[val];
                int loc_idx = loc.a + loc.b - 1;
                if (ans[loc_idx] > 0) // there is answer in that position already
                    continue;
                set<int>::iterator it = ans_ex.lower_bound(loc_idx);
                // check left and right
                if (!is_rb(loc, loc_dict[ans[*it]]))
                    continue;
                --it;
                if (!is_rb(loc_dict[ans[*it]], loc))
                    continue;

                ans[loc_idx] = val;
                ans_ex.insert(loc_idx);
            }
        }
        if (r + c - 1 <= 200) {
            rep1(idx, r + c - 1) {
                printf("%07d\n", ans[idx]);
            }
        } else {
            for (int idx = 1; idx <= 100; ++idx)
                printf("%07d\n", ans[idx]);
            for (int idx = r + c - 100; idx <= r + c - 1; ++idx)
                printf("%07d\n", ans[idx]);
        }
    }

#ifdef DEBUG
    rep_rt();
#endif
    return 0;
}
