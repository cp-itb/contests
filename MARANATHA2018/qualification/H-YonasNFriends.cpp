/**
 * Contest : Maranatha 2018 Qualification
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : H - Card Sort
 */
#include <string.h>
#include <stdio.h>


void solve() {
    int n, i, j, count, a, b;
    char s[10];
    int cek[13][4];
    scanf("%d", &n);
    memset(cek, 0, sizeof cek);
    for (i=0; i<n; i++) {
        scanf("%s", s);
        a = -1, b = -1;
        if (s[2] == 0) {
            if (s[0] == 'A') a = 0;
            if (s[0] == '2') a = 1;
            if (s[0] == '3') a = 2;
            if (s[0] == '4') a = 3;
            if (s[0] == '5') a = 4;
            if (s[0] == '6') a = 5;
            if (s[0] == '7') a = 6;
            if (s[0] == '8') a = 7;
            if (s[0] == '9') a = 8;
            if (s[0] == 'J') a = 10;
            if (s[0] == 'Q') a = 11;
            if (s[0] == 'K') a = 12;

            if (s[1] == 'S') b = 0;
            if (s[1] == 'H') b = 1;
            if (s[1] == 'D') b = 2;
            if (s[1] == 'C') b = 3;
        } else {
            a = 9;

            if (s[2] == 'S') b = 0;
            if (s[2] == 'H') b = 1;
            if (s[2] == 'D') b = 2;
            if (s[2] == 'C') b = 3;
        }
        cek[a][b]++;
    }
    count = 0;
    for (i=0; i<13; i++) {
        for (j=0; j<4; j++) {
            if (cek[i][j] > 0) count++;
        }
    }
    if (count == 52) {
        printf("FULLHOUSE %d\n", n-52);
    } else {
        printf("INCOMPLETE\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}