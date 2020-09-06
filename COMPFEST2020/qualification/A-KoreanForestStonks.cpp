
/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Jun Ho Choi Hedyatmo, Morgen Sudyanto, Michel Fang
 * Problem : A - Angka Cantik
 */
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int dig[n];
    for (int i = 0; i < n; i++) cin >> dig[i];
    sort(dig, dig + n);

    map<ll, int> vis;
    ll cur = 0;
    for (int i = 1; i <= m + 1; i++) {
        cur = (cur * 10 + 1) % m;
        if (vis[cur]) {
            for (int k = 1; k < n; k++) {
                for (int j = i - vis[cur]; j > 0; j--) cout << dig[k];
                for (int j = vis[cur]; j > 0; j--) cout << 0;
            }
            cout << 0 << '\n';
            exit(0);
        } else {
            vis[cur] = i;
        }
    }
    cout << -1 << '\n';
    return 0;
}