/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Morgen Sudyanto, Michel Fang
 * Problem : E - Ujian Penyihir
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x,m;
    cin >> n >> x >> m;
    int tx = x;
    while (m--) {
        int l,r;
        cin >> l >> r;
        x = min(x, r-l+1);
    }
    cout << x+1 << endl;
    for (int i=0;i<n;i++) cout << tx - (i%x+1) << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}