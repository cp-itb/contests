/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : H
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;

int n, m, q;
vector<vector<ll>> mat;

ll hitung(int xa, int ya, int xb, int yb){
    return mat[xb][yb] - mat[xa - 1][yb] - mat[xb][ya - 1] + mat[xa - 1][ya - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    mat.resize(n + 1, vector<ll>(m + 1, 0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mat[i][j];  
        }
    }
    for (int i=1;i<=n;i++){
        ll cur = 0;
        for (int j=1;j<=m;j++){
            cur += mat[i][j];
            mat[i][j] = cur + mat[i - 1][j];
        }
    }
    while (q--){
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        cout << hitung(xa, ya, xb, yb) << el;
    }

    return 0;
}