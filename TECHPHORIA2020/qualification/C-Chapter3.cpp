/**
 * Contest : Techphoria 2020 - Qualification
 * Team    : Chapter3
 * Author  : Muhammad Kamal Shafi
 * Problem : C
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

const int N = 1e3 + 20, M = 12;
const int INF = 1e9;

vector<string> quer;
int n;
int ar[N];
int dp[N][M][M];

int tam(int a, int b){
    int ret = a + b;
    if (ret < 0) ret += 10;
    if (ret >= 10) ret -= 10;
    return ret; 
}

void solve(){
    if (n == 1){
        cout << min(ar[1], 10 - ar[1]) << el;
        return;
    }
    for (int i=0;i<=n + 10;i++){
        for (int j=0;j<M;j++){
            for (int k=0;k<M;k++){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][ar[1]][ar[2]] = 0;
    for (int i=1;i<=n;i++){
        for (int kur=-9;kur<=9;kur++){
            for (int j=0;j<10;j++){
                for (int k=0;k<10;k++){
                    int tm = abs(kur);
                    // 1
                    dp[i - 1][tam(j, kur)][k] = min(dp[i - 1][tam(j, kur)][k], dp[i - 1][j][k] + tm);
                    // 2
                    dp[i - 1][tam(j, kur)][tam(k, kur)] = min(dp[i - 1][tam(j, kur)][tam(k, kur)], dp[i - 1][j][k] + tm);
                }
            }
        }
        for (int j=0;j<10;j++){
            for (int k=0;k<10;k++){
                int a = -j;
                int b = 10 - j;
                
                // 1
                dp[i][k][ar[i + 2]] = min(dp[i][k][ar[i + 2]], dp[i - 1][j][k] + min(abs(a), abs(b)));
                // 2
                dp[i][tam(k, a)][ar[i + 2]] = min(dp[i][tam(k, a)][ar[i + 2]], dp[i - 1][j][k] + abs(a));
                dp[i][tam(k, b)][ar[i + 2]] = min(dp[i][tam(k, b)][ar[i + 2]], dp[i - 1][j][k] + abs(b));
                // 3
                dp[i][tam(k, a)][tam(ar[i + 2], a)] = min(dp[i][tam(k, a)][tam(ar[i + 2], a)], dp[i - 1][j][k] + abs(a));
                dp[i][tam(k, b)][tam(ar[i + 2], b)] = min(dp[i][tam(k, b)][tam(ar[i + 2], b)], dp[i - 1][j][k] + abs(b));
            }
        }
    }
    int ans = INF;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            ans = min(ans, dp[n][i][j]);
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    {
        string temp;
        while (cin >> temp){
            quer.pb(temp);
        }
    }
    int q = quer.size();
    for (int i=0;i<q;i+=2){
        assert(quer[i].size() == quer[i + 1].size());
        n = quer[i].size();
        string a = quer[i];
        string b = quer[i + 1];
        for (int j=1;j<=n;j++){
            ar[j] = (int(a[j - 1] - b[j - 1]) + 10) % 10;
            // cout << ar[j] << " ";
        }
        // cout << el;
        solve();
    }

    return 0;
}