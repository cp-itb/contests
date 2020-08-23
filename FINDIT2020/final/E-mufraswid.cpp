/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Michel Fang
 * Problem : E - WA Image
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
    int n, k;
    cin >> n >> k;
    map<string, int> cnt;
    map<vector<string>, vector<string>> lol;
    for (int i = 0; i < n; i++) {
        string ss;
        int v;
        cin >> ss >> v;
        cnt[ss] = v;
        for (int j = 0; j < v; j++) {
            string s[k];
            for (int l = 0; l < k; l++) {
                cin >> s[l];
            }

            vector<string> xd;
            string tmp;
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    tmp.pb(s[i][j]);
                }
            }
            xd.pb(tmp);

            tmp.clear();
            for (int j = 0; j < k; j++) {
                for (int i = k - 1; i >= 0; i--) {
                    tmp.pb(s[i][j]);
                }
            }
            xd.pb(tmp);

            tmp.clear();
            for (int i = k - 1; i >= 0; i--) {
                for (int j = k - 1; j >= 0; j--) {
                    tmp.pb(s[i][j]);
                }
            }
            xd.pb(tmp);

            tmp.clear();
            for (int j = k - 1; j >= 0; j--) {
                for (int i = 0; i < k; i++) {
                    tmp.pb(s[i][j]);
                }
            }
            xd.pb(tmp);

            sort(xd.begin(), xd.end());
            lol[xd].pb(ss);
        }
    }
    for (auto& it: lol) {
        sort(it.se.begin(), it.se.end());
        for (int i = 1; i < sz(it.se); i++) {
            cnt[it.se[i]]--;
        }
    }
    for (auto it: cnt) {
        cout << it.fi << ' ' << it.se << '\n';
    }
    return 0;
}