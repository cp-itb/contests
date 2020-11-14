/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : G
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

const ll MX = (1LL << 32) - 1;

int n;
stack<ll> st;
ll cur = 1;
ll ans = 0;

int dep = 0;
int lcnt = 0;
// bool lebih = 0;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        if (s == "for" || s == "For"){
            ll x;
            cin >> x;
            if (cur > MX){
                lcnt++;
            } else{
                cur *= x;
                st.push(x);
            }
        } else if (s == "end"){
            if (lcnt){
                lcnt--;
            } else{
                cur /= st.top();
                st.pop();
            }
        } else{
            if (cur <= MX){
                ans += cur;
            } else{
                cout << "OVERFLOW!!!" << el;
                return 0;
            }
        }
        if (ans > MX){
            cout << "OVERFLOW!!!" << el;
            return 0;
        }
    }
    cout << ans << el;

    return 0;
}

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;
const ll INF = 1e18;

int n;
ll ar[N][5]; // col, row
ll dp[N][5];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=3;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[j][i];
        }
    }
    for (int i=0;i<n + 1;i++){
        fill(dp[i], dp[i] + 5, -INF);
    }
    dp[1][1] = ar[1][1];
    for (int i=1;i<=n;i++){
        if (i == n){
            for (int j=1;j<=3;j++){
                ll cur = 0;
                for (int j2=j + 1;j2<=3;j2++){
                    cur += ar[i][j2];
                }
                dp[i][3] = max(dp[i][3], dp[i][j] + cur);
            }
            continue;
        }
        for (int j=1;j<=3;j++){
            if (j == 1){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + ar[i + 1][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + ar[i][j + 1] + ar[i + 1][j + 1]);
                dp[i + 1][j + 2] = max(dp[i + 1][j + 2], dp[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 2]);

                ll cur = dp[i][j] + ar[i + 1][j] + ar[i + 1][j + 1] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 2];
                if (i == n - 1){
                    dp[i + 1][3] = max(dp[i + 1][3], cur);
                } else{
                    dp[i + 2][3] = max(dp[i + 2][3], cur + ar[i + 2][3]);
                }
            } else if (j == 2){
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + ar[i][j - 1] + ar[i + 1][j - 1]);
                dp[i + 1][2] = max(dp[i + 1][2], dp[i][j] + ar[i + 1][j]);
                dp[i + 1][3] = max(dp[i + 1][3], dp[i][j] + ar[i][j + 1] + ar[i + 1][j + 1]);
            } else{
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + ar[i + 1][j]);
                dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + ar[i][j - 1] + ar[i + 1][j - 1]);
                dp[i + 1][j - 2] = max(dp[i + 1][j - 2], dp[i][j] + ar[i][j - 1] + ar[i][j - 2] + ar[i + 1][j - 2]);

                ll cur = dp[i][j] + ar[i + 1][j] + ar[i + 1][j - 1] + ar[i][j - 1] + ar[i][j - 2] + ar[i + 1][j - 2];
                
                if (i < n - 1){
                    dp[i + 2][1] = max(dp[i + 2][1], cur);
                }
            }
        }
    }
    cout << dp[n][3] << el;

    return 0;
}