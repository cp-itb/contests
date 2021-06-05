 /**
  * Contest : Joints 2021 Final
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

const int N = 1e6 + 10;
const int INF = 1e9;

ll money; //
int konten = 0;
int c, t, n;
vector<pii> pos, neg;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> money >> c >> t >> n;
    money -= c + t;
    if (money < 0){
        cout << "Gagal" << el;
        return 0;
    }
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        if (b - a >= 0) pos.pb(mp(a, b - a));
        else neg.pb(mp(b - a, a));
    }
    sort(pos.begin(), pos.end());
    for (auto& x : pos){
        if (money >= x.fi){
            money += x.se;
            konten++;
        }
    }
    sort(neg.begin(), neg.end(), greater<pii>());
    for (auto& x : neg){
        if (money >= x.se){
            money += x.fi;
            konten++;
        }
    }
    if (konten == 0){
        cout << "Gagal" << el;
        return 0;
    }
    cout << konten << " " << money << el;

    return 0;
}