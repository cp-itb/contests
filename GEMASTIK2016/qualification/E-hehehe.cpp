/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : hehehe
 * Author  : Willy
 * Problem : E - Libur Tahun Baru
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

#define MAXS 1010

int prev_dp[MAXS + 1], dp[MAXS + 1], next_dp[MAXS + 1];

int main() {
#ifdef DEBUG
    freopen("E.in", "r", stdin);
#endif

    int nt;
    scanf("%d", &nt);
    while (nt--) {
        rep(val, MAXS + 1) {
            prev_dp[val] = NINF;
            dp[val] = NINF;
        }

        int n, s, p;
        scanf("%d %d %d", &n, &s, &p);

        prev_dp[0] = dp[0] = 0; // from city 1
        for (int city_id = 1; city_id <= (n - 1); ++city_id) {
            for (int val = 0; val <= s; ++val) { // assume there is no way you can reach the next city ended with that value
                next_dp[val] = NINF;
            }

            int k, v;
            scanf("%d %d", &k, &v);
            for (int val = 0; val <= s; ++val) {
                if (val + k <= s) { // by train
                    next_dp[val + k] = max(next_dp[val + k], dp[val] + v);
                }
                if (val + p <= s) { // by plane
                    next_dp[val + p] = max(next_dp[val + p], prev_dp[val]);
                }
            }
            for (int val = 0; val <= s; ++val) {
                dp[val] = next_dp[val];
                prev_dp[val] = max(prev_dp[val], dp[val]);
            }
        }
        int ans = -1;
        for (int val = 0; val <= s; ++val) {
            ans = max(ans, dp[val]);
        }
        printf("%d\n", ans);
    }

#ifdef DEBUG
    rep_rt();
#endif
    return 0;
}
