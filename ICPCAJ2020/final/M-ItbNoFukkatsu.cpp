/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : M
 */
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int INF = 1e7;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> x(n), y(n);
 
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
 
    auto F = [&](vector<int>& v, int pos) {
        int ret = 0;
        for (int x : v) ret = max(ret, abs(pos - x));
        return ret;
    };
 
    auto getX = [&](vector<int>& v) -> int {
        int l = -INF, r = INF;
        while (r - l >= 3) {
            int p1 = l + (r - l) / 3;
            int p2 = r - (r - l) / 3;
            if (F(v, p1) > F(v, p2)) {
                l = p1;
            } else {
                r = p2;
            }
        }
        int ans = INF * 3;
        for (int i = l; i <= r; i++) {
            ans = min(ans, F(v, i));
        }
        return ans;
    };
 
    cout << getX(x) << " " << getX(y) << '\n';
 
    return 0;
}  