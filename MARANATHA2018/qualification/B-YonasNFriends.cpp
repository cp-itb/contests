/**
 * Contest : Maranatha 2018 Qualification
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : B - The Nationals
 */
#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
    int n;
    int ans;
    scanf("%d", &n);
    printf("Case #%d: ", tc);
    if (n == 2) printf("3 5\n");
    if (n == 4) printf("7 14\n");
    if (n == 8) printf("9 20\n");
    if (n == 16) printf("11 26\n");
    if (n == 32) printf("13 32\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}