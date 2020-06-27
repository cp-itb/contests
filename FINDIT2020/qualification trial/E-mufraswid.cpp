/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Morgen Sudyanto
 * Problem : E - Bilangan Kompleks
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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << a*c-b*d << " " << a*d+b*c << "i" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}