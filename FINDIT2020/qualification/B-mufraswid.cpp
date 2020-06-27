/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Morgen Sudyanto
 * Problem : B - Menggambar Molekul
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
    int n,m;
    cin >> n >> m;
    char a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    char p[3*n+5][3*m+5];
    for (int i=0;i<=3*n+2;i++) {
        for(int j=0;j<=3*m+2;j++) {
            p[i][j] = ' ';
        }
    }
    int k = 3;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] == '0') {
                if (p[k][3*j+1] == ' ') p[k][3*j+1] = '_';
                if (p[k+1][3*j] == ' ') p[k+1][3*j] = '/';
                if (p[k+1][3*j+2] == ' ') p[k+1][3*j+2] = '\\';
                if (p[k+2][3*j] == ' ') p[k+2][3*j] = '\\';
                if (p[k+2][3*j+2] == ' ') p[k+2][3*j+2] = '/';
                if (p[k+2][3*j+1] == ' ') p[k+2][3*j+1] = '_';
            } else if (a[i][j] == '-') {
                p[k+1][3*j] = '_';
                p[k+1][3*j+1] = '_';
                p[k+1][3*j+2] = '_';
            } else {
                p[k+1][3*j+1] = '|';
                p[k+2][3*j+1] = '|';
            }
        }
        k += 2;
    }
    for (int i=3;i<=k;i++) {
        for(int j=3;j<=3*m+2;j++) {
            cout << p[i][j];
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}