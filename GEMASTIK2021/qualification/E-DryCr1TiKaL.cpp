 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : DryCr1TiKaL
  * Author  : Morgen Sudyanto
  * Problem : E - Bitcoin
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
    LL n;
    cin >> n;
    LL ans = 0;
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=2;i<=n;i++) {
        ans += max(a[i]-a[i-1], 0LL);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}