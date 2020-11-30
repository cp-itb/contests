/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : M
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

int n;
int ar[N];
bool dapet[N];
int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    dapet[0] = 1;
    dapet[n + 1] = 1;
    for (int i=1;i<=n;i++){
        for (int j=i-1;j<=i+1;j++){
            if (!dapet[j] && ar[i]){
                dapet[j] = 1;
                ar[i]--;
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (dapet[i]) ans++;
    }
    cout << ans << el;

    return 0;
}