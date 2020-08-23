/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Morgen Sudyanto
 * Problem : A - Tumpukan Balok
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for(LL i=1;i<=n;i++) cin >> a[i];
    LL b[n+5];
    for (LL i=1;i<=n;i++) cin >> b[i];
    LL xa[n+5], xb[n+5];
    memset (xa,0,sizeof(xa));
    memset (xb,0,sizeof(xb));

    stack<pii> s;
    LL cur = 0;
    for (LL i=1;i<=n;i++) {
        bool done = 0;
        // if (i > 1 && a[i-1] < a[i]) {
        //     // s.pop();
        //     x[i] += cur;
        //     cout << cur << " ";
        //     done = 1;
        // }
        while (!s.empty() && s.top().fi <= a[i]) {
            cur -= s.top().se;
            s.pop();
        }
        s.push({a[i], b[i]});
        if (!done) {
            xa[i] += cur;
        }
        cur += b[i];
        if (i > 1 && a[i-1] < a[i]) xa[i] = xa[i-1];
    }

    while (!s.empty()) s.pop();

    cur = 0;
    for (LL i=n;i>=1;i--) {
        bool done = 0;
        // if (i < n && a[i+1] < a[i]) {
        //     // s.pop();
        //     x[i] += cur;
        //     cout << cur << " ";
        //     done = 1;
        // }
        while (!s.empty() && s.top().fi <= a[i]) {
            cur -= s.top().se;
            s.pop();
        }
        s.push({a[i], b[i]});
        if (!done) {
            xb[i] += cur;
        }
        cur += b[i];
        if (i < n && a[i+1] < a[i]) xb[i] = xb[i+1];
    }

    // for (LL i=1;i<=n;i++) cout << xa[i] << " ";
    // cout << endl;
    // for (LL i=1;i<=n;i++) cout << xb[i] << " ";
    // cout << endl;
    // for (LL i=1;i<=n;i++) cout << xa[i] + xb[i] << " ";
    // cout << endl;
    LL maxi = 0;
    for (LL i=1;i<=n;i++) {
        maxi = max(maxi, xa[i] + xb[i]);
    }
    for (LL i=1;i<=n;i++) {
        if (xa[i] + xb[i] == maxi) cout << i << " ";
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}