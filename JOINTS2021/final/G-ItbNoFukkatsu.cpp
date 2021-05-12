 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Farras Faddila, Muhammad Hasan
  * Problem : G
  */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e3 + 5;
const int INF = 2e9;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

int n, m;
ll a, b;
ll area;
int p[N][N];
int t[4 * N][4 * N];

ll __p1[N][N], __p2[N][N];
ll * _p1[N];
ll * _p2[N];
ll ** p1 = _p1 + 1;
ll ** p2 = _p2 + 1;

void init(){
    for (int i=0;i<N;i++){
        _p1[i] = __p1[i] + 1;
        _p2[i] = __p2[i] + 1;
    }
}

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = p[lx][ly];
        else
            t[vx][vy] = min(t[vx*2][vy], t[vx*2+1][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = min(t[vx][vy*2], t[vx][vy*2+1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}

int min_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return INF;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return min(min_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)), min_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
}

int min_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return INF;
    if (lx == tlx && trx == rx)
        return min_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return min(min_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry), min_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
}

ll sum1(int px, int qx, int py, int qy) {
    return p1[qx][qy] - p1[qx][py - 1] - p1[px - 1][qy] + p1[px - 1][py - 1];
}

ll sum2(int px, int qx, int py, int qy) {
    return p2[qx][qy] - p2[qx][py - 1] - p2[px - 1][qy] + p2[px - 1][py - 1];
}

ll query(ll px, ll qx, ll py, ll qy) {
    ll mn = (ll) min_x(1, 0, n - 1, px, qx, py, qy);
    return sum2(px, qx, py, qy) - 2 * mn * sum1(px, qx, py, qy) + mn * mn * area; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    in(n), in(m), in(a), in(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in(p[i][j]);
        }
    }

    init();
    area = a * b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll x = (ll) p[i][j];
            p1[i][j] = p1[i - 1][j] + p1[i][j - 1] + x - p1[i - 1][j - 1];
            p2[i][j] = p2[i - 1][j] + p2[i][j - 1] + x * x - p2[i - 1][j - 1];
        }
    }

    build_x(1, 0, n - 1);

    ll ans = 1e18;
    for (int i = 0; i + a - 1 < n; i++) {
        for (int j = 0; j + b - 1 < m; j++) {
            ans = min(ans, query(i, i + a - 1, j, j + b - 1));
        }
    }
    if (a != b) {
        for (int i = 0; i + b - 1 < n; i++) {
            for (int j = 0; j + a - 1 < m; j++) {
                ans = min(ans, query(i, i + b - 1, j, j + a - 1));
            }
        }
    }
    out(ans, '\n');

    return 0;
}