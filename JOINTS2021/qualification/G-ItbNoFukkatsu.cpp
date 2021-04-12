/**
  * Contest : Joints 2021 Qualification
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Kamal Shafi
  * Problem : G
***/
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n, m;
int ar[N];
ll ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n + m;i++){
        cin >> ar[i];
        ans += ar[i];
    }
    for (int i=1;i<=n + m;i++){
        int a;
        cin >> a;
        ar[i] = a - ar[i];
    }
    sort(ar + 1, ar + n + m + 1);
    for (int i=1;i<=m;i++){
        ans += ar[i];
    }
    cout << ans << el;

    return 0;
}