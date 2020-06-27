/**
 * Contest : FINDIT 2020
 * Team    : musfraswid
 * Author  : Morgen Sudyanto
 * Problem : B - Anak Kadal Belajar Menghitung
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
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if (x%2==0) cout << x+1 << " " << x+3 << " " << x+5 << endl;
        else cout << x+2 << " " << x+4 << " " << x+6 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}