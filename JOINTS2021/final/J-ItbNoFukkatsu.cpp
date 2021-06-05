 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Kamal Shafi
  * Problem : J
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

const int N = 1e5 + 10;
const int MASK = 3;
const ll INF = 1e18;

int n;
ll mx[(1 << MASK)];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(mx, mx + (1 << MASK), -INF);

    cin >> n;
    for (int i=1;i<=n;i++){
        vector<ll> vec(3);
        cin >> vec[0] >> vec[1];
        vec[2] = (ll)i;
        for (int mask=0;mask<(1 << MASK);mask++){
            ll tot = 0;
            for (int pos=0;pos<MASK;pos++){
                if (mask & (1 << pos)){
                    tot += vec[pos];
                } else{
                    tot -= vec[pos];
                }
            }
            mx[mask] = max(mx[mask], tot);
        }
    }
    ll ans = -INF;
    for (int mask=0;mask<(1 << MASK);mask++){
        int flip = (1 << MASK) - 1 - mask;
        ans = max(ans, mx[mask] + mx[flip]);
    }
    cout << ans << el;

    return 0;
}