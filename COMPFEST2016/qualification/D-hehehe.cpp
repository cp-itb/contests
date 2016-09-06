/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : hehehe
 * Author  : Aufar Gilbran
 * Problem : D - Bayi Chanek
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int main()
{
    int ans[] = { 0, 13, 23, 291, 576, 4895, 9261, 67163, 127597, 850659 };
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", ans[N]);
    }
}
