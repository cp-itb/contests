/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Michel Fang
 * Problem : A - Battle Royale
 */
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// using vi = vector<int>;
// using vvi = vector<vi>;
// using vll = vector<ll>;
// using vvll = vector<vll>;
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int ar[n];
    for (int i =  1; i <= n; i++) {
        cin >> ar[i];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        bool can = false;
        vector<bool> visa(n + 1, 0), visb(n + 1, 0);
        while (a != 1) {
            visa[a] = true;
            a = ar[a];
        }
        while (b != 1) {
            visb[b] = true;
            b = ar[b];
        }
        for (int i = 2; i <= n; i++) {
            if (visa[i] && visb[i]) {
                can = true;
                break;
            }
        }
        cout << (can ? "Ya" : "Tidak") << '\n';
    }
    return 0;
}