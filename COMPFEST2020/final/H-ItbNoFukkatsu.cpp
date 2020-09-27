/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : H
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

int q;
int a, b, c, d;

void solve(){
    cin >> a >> b >> c >> d;
    int sign = (a + b) & 1;
    if (sign) sign = -sign;
    else sign = 1;

    int mag = 0;
    if (a || d) mag = 2;
    if (b || c) mag++;
    bool ans[4] = {0, 0, 0, 0};
    if (mag >= 2 && sign == -1) ans[0] = 1;
    if ((mag & 1) && sign == -1) ans[1] = 1;
    if ((mag & 1) && sign == 1) ans[2] = 1;
    if (mag >= 2 && sign == 1) ans[3] = 1;
    for (int i=0;i<4;i++){
        if (ans[i]) cout << "Ya";
        else cout << "Tidak";
        if (i != 3) cout << " ";
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}