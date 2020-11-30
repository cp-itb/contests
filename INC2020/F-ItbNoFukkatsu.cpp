/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : F
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
const int M = 26;
const int INF = 1e9;

int n, k;
string s;
int pc[N][M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;
    s = "*" + s;

    for (int i=1;i<=n;i++){
        int dig = s[i] - 'A';
        for (int j=0;j<M;j++){
            pc[i][j] = pc[i - 1][j];
        }
        pc[i][dig]++;
    }
    int ans = INF;
    for (int i=k;i<=n;i++){
        for (int j=0;j<M;j++){
            ans = min(ans, k - (pc[i][j] - pc[i - k][j]));
        }
    }
    cout << ans << el;

    return 0;
}