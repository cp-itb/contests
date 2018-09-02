/**
 * Contest : Maranatha 2018 Qualification
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : G - Jumping Frog
 */
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];
long long b[100005];

void solve(int tc) {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    b[0] = 0LL;
    for (int i=1; i<=n; i++) {
        b[i] = -99999999999999LL;
        if (i-2>=0) b[i] = max(b[i], b[i-2] + a[i]);
        if (i-3>=0) b[i] = max(b[i], b[i-3] + a[i]);
        if (i-4>=0) b[i] = max(b[i], b[i-4] + a[i]);
        if (i-5>=0) b[i] = max(b[i], b[i-5] + a[i]);
    }
    long long ans = b[0];
    for (int i=0; i<=n; i++) {
        ans = max(ans, b[i]);
    }

    printf("Case %d :%lld\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}