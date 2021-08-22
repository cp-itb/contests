 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : DryCr1TiKaL
  * Author  : Morgen Sudyanto
  * Problem : G - Jalan Jalan Virtual
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

pii ans[100005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    int dx[] = {1, 0, -1, 0};   // timur barat
    int dy[] = {0, 1, 0, -1};   // utara selatan

    int cnt = 1;
    int ax = 0, ay = 0;
    ans[0] = {0, 0};
    for (int i=1;i<=100000;i++) {
        for (int j=1;j<=i;j++) {
            ax += dx[(i-1)%4];
            ay += dy[(i-1)%4];
            ans[cnt] = {ax, ay};
            cnt++;
            if (cnt == 100005) break;
        }
        if (cnt == 100005) break;
    }
    while (tc--) {
        int n;
        cin >> n;
        cout << ans[n].fi << " " << ans[n].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}