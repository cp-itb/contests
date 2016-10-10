/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Aufar Gilbran
 * Problem : K - Operations on Matrix
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 30
int tmp[MAXN+5][MAXN+5], a[MAXN+5][MAXN+5];
int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        while (q--) {
            string s;
            cin >> s;
            if (s[1] == 'o') {
                string t;
                cin >> t;
                if (t.size() == 2) {
                    int r, c, s;
                    scanf("%d%d%d", &r, &c, &s);
                    for (int i = 0; i <= s; ++i)
                        for (int j = 0; j <= s; ++j) {
                            tmp[r+i][c+j] = a[r+s-j][c+i];
                        }
                    for (int i = r; i <= r+s; ++i)
                        for (int j = c; j <= c+s; ++j)
                            a[i][j] = tmp[i][j];
                }
                else {
                    int r, c, s;
                    scanf("%d%d%d", &r, &c, &s);
                    for (int i = 0; i <= s; ++i)
                        for (int j = 0; j <= s; ++j) {
                            tmp[r+i][c+j] = a[r+j][c+s-i];
                        }
                    for (int i = r; i <= r+s; ++i)
                        for (int j = c; j <= c+s; ++j)
                            a[i][j] = tmp[i][j];
                }
            }
            else {
                string t;
                cin >> t;
                if (t[0] == 'x') {
                    int r1, r2, c1, c2;
                    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
                    int d = (r2-r1+1)/2;
                    for (int i = 0; i <= d; ++i) {
                        for (int j = c1; j <= c2; ++j) {
                            tmp[r1+i][j] = a[r2-i][j];
                            tmp[r2-i][j] = a[r1+i][j];
                        }
                    }
                    for (int i = r1; i <= r2; ++i)
                        for (int j = c1; j <= c2; ++j)
                            a[i][j] = tmp[i][j];
                }
                else {
                    int r1, r2, c1, c2;
                    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
                    int d = (c2-c1+1)/2;
                    for (int i = r1; i <= r2; ++i) {
                        for (int j = 0; j <= d; ++j) {
                            tmp[i][c1+j] = a[i][c2-j];
                            tmp[i][c2-j] = a[i][c1+j];
                        }
                    }
                    for (int i = r1; i <= r2; ++i)
                        for (int j = c1; j <= c2; ++j)
                            a[i][j] = tmp[i][j];
                }
            }
        }
        printf("Case #%d:\n", itc);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j > 1) printf(" ");
                printf("%d", a[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
