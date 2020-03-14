/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Morgen Sudyanto
 * Problem : F - Saklar Ajaib
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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans = 0;
    for (int i=1;i<=n;i++) {
        if ((a[i] + ans) % 2 == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}