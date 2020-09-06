/**
 * Contest : Compfest 2020 Penyisihan
 * Team    : Korean Forest Stonks
 * Author  : Morgen Sudyanto
 * Problem : B - Bintang Ojol
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
    LL n,m;
    cin >> n >> m;
    if (n > m * 5 || n < m) {
        cout << -1 << " " << -1 << endl;
    } else {
        LL x = 4 * m;
        cout << max(0LL, n-x) << " " << (n-m)/4 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}