/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Kamal Shafi
 * Problem : D - Musim Hujan
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 110;
const int INF = 1e8;

pii nex[4] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};

int q;
int n;
string s[N];
int a, b;

pii aw, ak;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            string temp;
            cin >> temp;
            s[i] = "*" + temp;
        }
        cin >> a >> b;
        aw.fi = (a - 1) / n + 1;
        aw.se = (a - 1) % n + 1;

        ak.fi = (b - 1) / n + 1;
        ak.se = (b - 1) % n + 1;

        set <pair<int, pii>> setdah; // cost, pos
        int dp[n + 2][n + 2];
        for (int i=0;i<n+2;i++){
            fill(dp[i], dp[i] + n + 2, INF);
        }
        dp[aw.fi][aw.se] = 0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                setdah.insert(mp(dp[i][j], mp(i, j)));
            }
        }

        while (!setdah.empty()){
            auto temp = *setdah.begin();
            pii cur = temp.se;
            int cost = temp.fi;
            setdah.erase(setdah.begin());

            for (int i=0;i<4;i++){
                int ni = cur.fi + nex[i].fi;
                int nj = cur.se + nex[i].se;
                if (ni > 0 && nj > 0 && ni <= n && nj <= n){
                    int tambah = (s[cur.fi][cur.se] != s[ni][nj]);
                    if (cost + tambah < dp[ni][nj]){
                        // pair<int, pii> baru = mp(cost + tambah, mp(ni, nj));
                        setdah.erase(mp(dp[ni][nj], mp(ni, nj)));
                        dp[ni][nj] = cost + tambah;
                        setdah.insert(mp(dp[ni][nj], mp(ni, nj)));
                    }
                }
            }
        }

        cout << dp[ak.fi][ak.se] << el;

    }

    return 0;
}