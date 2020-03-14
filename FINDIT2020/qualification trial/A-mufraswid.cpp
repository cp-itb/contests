/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Morgen Sudyanto
 * Problem : A - Kafe Programmer
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

bool cmp(pii a, pii b) {
    return a.se > b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    pii a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort (a+1,a+n+1);
    priority_queue<pii, vector<pii>, function<bool(pii, pii)>> p(cmp);
    LL cur = 0, ans = 0;
    for (LL i=1;i<=n;i++) {
        if (i == 1 || a[i].fi <= cur) {
            if (p.empty()) {
                cur = max(cur, a[i].fi);
            }
            p.push(a[i]);
        } else if (!p.empty()) {
            while (!p.empty() && a[i].fi > cur) {
                cur += p.top().se;
                ans += cur - p.top().fi;
                p.pop();
            }
            if (p.empty()) {
                cur = max(cur, a[i].fi);
            }
            p.push(a[i]);
        }
    }
    while (!p.empty()) {
        cur += p.top().se;
        ans += cur - p.top().fi;
        p.pop();
    }
    cout << ans/n << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}