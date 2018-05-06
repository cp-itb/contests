/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : Arurange Code Party
 * Author  : Dewita Sonya
 * Problem : E - Inaccurate Report
 */

#include <bits/stdc++.h>
using namespace std;

int n,m,r[10010]={},x,y,z,maks=0;
int d[10010]={}, p[10010][17];
vector<int> v[10010];

void dfs(int x, int pr, int vl) {
    p[x][0] = pr;
    d[x] = vl;
    for (auto& e:v[x]) {
        if (e==pr) continue;
        dfs(e, x, vl+1);
    }
}

int lca(int x, int y) {
    if (d[x]<d[y]) swap(x, y);  
    int dt = d[x]-d[y];
    for (int i=16;i>=0;--i) {
        if ((1<<i) <= dt) {
            x = p[x][i];
            dt -= (1<<i);
        }
    }
    if (x==y) return x;
    for (int i=16;i>=0;--i) {
        if (p[x][i]!=p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

int dist(int x, int y) {
    int lc = lca(x, y);
    return d[x]-d[lc]+d[y]-d[lc];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=1;i<n;++i) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0, 0);
    for (int j=1;j<=16;++j) {
        for (int i=1;i<=n;++i) {
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    while (m--) {
        scanf("%d %d", &x, &y);
        for (int i=1;i<=n;++i) {
            if (dist(x, i) == y) {
                ++r[i];
                maks = max(maks, r[i]);
            }
        }
    }
    printf("%d\n", maks);
    return 0;
}