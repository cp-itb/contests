#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;
const int M = 15;

int n, m;
int ar[N];
bool dp[(1 << M)], ndp[(1 << M)];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int k;
        cin >> k;
        for (int j=0;j<k;j++){
            int a;
            cin >> a;
            ar[i] |= (1 << (a - 1));
        }
    }
    int target = (1 << m) - 1;
    dp[0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<(1 << M);j++){
            if (!dp[j]) continue;
            ndp[(j ^ ar[i])] = 1;
        }
        for (int j=0;j<(1 << M);j++){
            dp[j] = (dp[j] || ndp[j]);
        }
    }
    if (dp[target]){
        cout << "YA" << el;
    } else{
        cout << "TIDAK" << el;
    }

    return 0;
}