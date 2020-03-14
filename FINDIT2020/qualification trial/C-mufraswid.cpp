/**
 * Contest : FINDIT 2020
 * Team    : musfraswid
 * Author  : Morgen Sudyanto
 * Problem : C - Eternal Labyrinth
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
    int r,c;
    cin >> r >> c;
    int a[r+5][c+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == -1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=1;i<=r;i++) {
        if (a[i][1] == 0) a[i][1] = 1;
        else break;
    }
    for (int i=2;i<=c;i++) {
        if (a[1][i] == 0) a[1][i] = 1;  
        else break;      
    }
    for (int i=2;i<=r;i++) {
        for (int j=2;j<=c;j++) {
            if (a[i][j] == -1) continue;
            if (a[i-1][j] > 0) a[i][j] += a[i-1][j];
            if (a[i][j-1] > 0) a[i][j] += a[i][j-1];
        }
    }
    if (a[r][c] == -1) cout << 0 << endl;
    else cout << a[r][c] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}