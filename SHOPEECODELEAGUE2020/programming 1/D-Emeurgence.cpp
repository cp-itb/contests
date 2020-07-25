/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Emeurgence
* Author  : Muhammad Hasan
* Problem : D - Item Stock
*/
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9 + 5;
const int N = 1e5 + 5;

struct item {
    // stock = -1 -> derived
    int par;
    long long qt;
    long long stock;
    long long val;
};

int n;
item p[N];
int up[N];
int par[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    par[pv] = pu;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p[1].stock;
    p[1].par = p[1].qt = p[1].val = 1;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 2; i <= n; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            cin >> p[i].par >> p[i].qt;
            up[i] = p[i].par;
            p[i].stock = -1; // derived
            p[i].val = min(INF, p[i].qt * p[p[i].par].val);
            merge(p[i].par, i);
        } else {
            cin >> p[i].par >> p[i].qt >> p[i].stock;
            up[i] = p[i].par;
            long long curval = min(INF, p[i].stock * p[i].qt * p[p[i].par].val);
            int lca = fpar(p[i].par);
            if (p[lca].stock >= curval) {
                p[lca].stock -= curval;
            } else {
                p[i].stock = 0;
            }
            p[i].val = 1LL;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i].stock == -1) {
            p[i].stock = (p[up[i]].stock / p[i].qt);
        }
        cout << p[i].stock << '\n';
    }

    return 0;
}