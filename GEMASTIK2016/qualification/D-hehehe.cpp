/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : hehehe
 * Author  : Aufar Gilbran
 * Problem : D - Saklar Lhompat
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= a+b; ++i) {
            int tmp = b;
            int slot = 3*i+1;
            int g = min(b, 2*i);
            slot -= g;
            b -= g;
            slot -= 2*b+a;
            if (slot >= 0) {
                printf("%d\n", i);
                goto ok;
            }
            b = tmp;
        }
ok: {}
    }
}
