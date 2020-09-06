/**
 * Contest : Compfest 2020 Penyisihan
 * Team    : Korean Forest Stonks
 * Author  : Morgen Sudyanto
 * Problem : G - Gajah Malas
 */

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];

    set<int> s;
    for (int i=1;i<=n;i++) {
        s.insert(a[i]);
    }

    int cnt = 0;
    map<int,int> m;
    for (auto x : s) {
        cnt++;
        m[x] = cnt;
    }

    for (int i=1;i<=n;i++) a[i] = m[a[i]];

    int b[n+5];
    for (int i=1;i<=n;i++) {
        b[a[i]] = i;
    }

    bool done[n+5];
    memset (done,0,sizeof(done));

    int cur = 0;
    for (int i=1;i<=n;i++) {
        if (b[i] > cur) {
            done[i] = 1;
            cur = b[i];
        } else break;
    }

    // for (int i=1;i<=n;i++) cout << b[i] << " ";
    // for (int i=1;i<=n;i++) cout << done[i] << " ";

    cur = n+1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) {
            if (b[i] < cur) {
                done[i] = 1;
                cur = b[i];
            } else break;
        }
    }

    bool y = 1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) y = 0;
    }
    if (y) {
        cout << "Ya" << endl;
        return 0;
    }
    
    // EUY
    reverse(a+1,a+n+1);
    set<int> s2;
    for (int i=1;i<=n;i++) {
        s2.insert(a[i]);
    }

    cnt = 0;
    for (auto x : s2) {
        cnt++;
        m[x] = cnt;
    }

    for (int i=1;i<=n;i++) a[i] = m[a[i]];

    for (int i=1;i<=n;i++) {
        b[a[i]] = i;
    }

    memset (done,0,sizeof(done));

    cur = 0;
    for (int i=1;i<=n;i++) {
        if (b[i] > cur) {
            done[i] = 1;
            cur = b[i];
        } else break;
    }

    // for (int i=1;i<=n;i++) cout << b[i] << " ";
    // for (int i=1;i<=n;i++) cout << done[i] << " ";

    cur = n+1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) {
            if (b[i] < cur) {
                done[i] = 1;
                cur = b[i];
            } else break;
        }
    }

    y = 1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) y = 0;
    }
    if (y) {
        cout << "Ya" << endl;
        return 0;
    }
    
    // EUY
    for (int i=1;i<=n;i++) a[i] *= -1;
    set<int> s3;
    for (int i=1;i<=n;i++) {
        s3.insert(a[i]);
    }

    cnt = 0;
    for (auto x : s3) {
        cnt++;
        m[x] = cnt;
    }

    for (int i=1;i<=n;i++) a[i] = m[a[i]];

    for (int i=1;i<=n;i++) {
        b[a[i]] = i;
    }

    memset (done,0,sizeof(done));

    cur = 0;
    for (int i=1;i<=n;i++) {
        if (b[i] > cur) {
            done[i] = 1;
            cur = b[i];
        } else break;
    }

    // for (int i=1;i<=n;i++) cout << b[i] << " ";
    // for (int i=1;i<=n;i++) cout << done[i] << " ";

    cur = n+1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) {
            if (b[i] < cur) {
                done[i] = 1;
                cur = b[i];
            } else break;
        }
    }

    y = 1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) y = 0;
    }
    if (y) {
        cout << "Ya" << endl;
        return 0;
    }

    //EUY
    reverse(a+1,a+n+1);
    set<int> s4;
    for (int i=1;i<=n;i++) {
        s4.insert(a[i]);
    }

    cnt = 0;
    for (auto x : s4) {
        cnt++;
        m[x] = cnt;
    }

    for (int i=1;i<=n;i++) a[i] = m[a[i]];

    for (int i=1;i<=n;i++) {
        b[a[i]] = i;
    }

    done[n+5];
    memset (done,0,sizeof(done));

    cur = 0;
    for (int i=1;i<=n;i++) {
        if (b[i] > cur) {
            done[i] = 1;
            cur = b[i];
        } else break;
    }

    // for (int i=1;i<=n;i++) cout << b[i] << " ";
    // for (int i=1;i<=n;i++) cout << done[i] << " ";

    cur = n+1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) {
            if (b[i] < cur) {
                done[i] = 1;
                cur = b[i];
            } else break;
        }
    }

    y = 1;
    for (int i=1;i<=n;i++) {
        if (!done[i]) y = 0;
    }
    if (y) {
        cout << "Ya" << endl;
        return 0;
    }


    cout << "Tidak" << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}