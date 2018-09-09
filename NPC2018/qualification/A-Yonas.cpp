#include <bits/stdc++.h>
#define MAXT 100000
#define ld long double
using namespace std;

int m[MAXT+5];
int n[MAXT+5];
bool a[MAXT+5][10];
pair<int, int> p[MAXT];
ld ans[MAXT+5];

ld f(int ai, int x) {
    return (ai + sqrt(ai*ai + 4*x)) / 2.0;
    ld ans = 1;
    for (int i=0; i<50; i++) {
        ans *= ai;
        ans += x;
        ans = sqrt(ans);
    }
    return ans;
}

int main() {
    int t, x;
    memset(a, false, sizeof a);

    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        scanf("%d%d", &m[i], &n[i]);
        for (int j=0; j<m[i]; j++) {
            scanf("%d", &x);
            a[i][x] = true;
        }
        p[i] = make_pair(n[i], i);
    }

    sort(p, p+t);
    int survey = 0;
    ld sliding[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int _i=0; _i<t; _i++) {
        int tc = p[_i].second;
        while (survey < n[tc]) {
            for (int i=1; i<=8; i++) {
                sliding[i] += f(i, survey);
            }
            survey++;
        }
        ans[tc] = 0.00;
        for (int i=1; i<=8; i++) {
            if (a[tc][i]) {
                ans[tc] += sliding[i] / survey;
            }
        }
        ans[tc] /= m[tc];
    }

    for (int i=0; i<t; i++) {
        printf("%.4Lf\n", ans[i]);
    }
}