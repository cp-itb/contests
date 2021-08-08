 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : DryCr1TiKaL
  * Author  : Morgen Sudyanto
  * Problem : A - Undian Berhadiah
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
    int n, x;
    cin >> n >> x;
    vector<int> k;
    for (int i=1;i<=n;i++) {
        int y;
        cin >> y;
        k.pb(y);
    }
    int mini = INT_MAX;
    for (auto p : k) {
        mini = min(mini, abs(x - p));
    }
    vector<int> ans;
    for (auto p : k) {
        if (abs(x - p) == mini) {
            ans.pb(p);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto p : ans) {
        if (p < 10) cout << "0000" << p;
        else if (p < 100) cout << "000" << p;
        else if (p < 1000) cout << "00" << p;
        else if (p < 10000) cout << "0" << p;
        else if (p < 100000) cout << "" << p;
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
4 00004
00007
02345
01111
00001
*/