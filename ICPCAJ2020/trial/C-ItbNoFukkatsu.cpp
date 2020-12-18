/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Farras Mohammad Hibban Faddila
 * Problem : C
 */
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5;
 
int n, q;
int r[N + 5], c[N + 5];
int pr[N + 5], pc[N + 5];
 
 
int main(){
 
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        pr[i] = pr[i - 1] + (r[i] & 1);
        pc[i] = pc[i - 1] + (c[i] & 1);
    }
    while (q--) {
        int ra, ca, rb, cb;
        cin >> ra >> ca >> rb >> cb;
        bool ok = 1;
        ok &= ((r[ra] + c[ca]) % 2 == 0);
        ok &= ((r[rb] + c[cb]) % 2 == 0);
        if (ra < rb) swap(ra, rb);
        if (ca < cb) swap(ca, cb);
        int dr = pr[ra] - pr[rb - 1];
        int dc = pc[ca] - pc[cb - 1];
        ok &= (dr == 0 || dr == (ra - rb + 1));
        ok &= (dc == 0 || dc == (ca - cb + 1));
        cout << (ok ? "YES" : "NO");
        cout << '\n';
    }
 
    return 0;
}