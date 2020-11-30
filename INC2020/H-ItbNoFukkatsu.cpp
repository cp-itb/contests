/**
 * Contest  : INC 2020
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Hasan
 * Problem  : H
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int n, m;
int a[N];
bool vis[N];

struct Segtree {
    vector<int> t;
    Segtree() {
        t.assign(4 * N, 0);
    }

    int combine(const int& x, const int& y) {
        return (x < y ? x : y);
    }

    void build(int v, int s, int e) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, int val) {
        if (s == e && s == pos) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    int get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return INF;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        int p1 = get(v << 1, s, mid, l, r);
        int p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
} sgt, sgt2;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sgt.build(1, 1, n);
    sgt2.build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        int atL = 0;
        {
            int l = 1, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sgt2.get(1, 1, n, 1, mid) > x) {
                    l = mid + 1;
                    atL = mid;
                } else {
                    r = mid - 1;
                }
            }    
        }
        int posL = n + 1;
        if (atL + 1 <= n && a[atL + 1] <= x) {
            posL = atL + 1;
        }
        int atR = 0;
        {
            int l = 1, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sgt.get(1, 1, n, 1, mid) >= x) {
                    l = mid + 1;
                    atR = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        int posR = n + 1;
        if (atR + 1 <= n && a[atR + 1] < x) {
            debug() << imie(atR + 1) imie(a[atR + 1]);
            posR = atR + 1;
        }
        int curPos = min(posL, posR);
        if (curPos > n) continue;
        sgt.update(1, 1, n, curPos, x);
        sgt2.update(1, 1, n, curPos, INF);
        a[curPos] = x;
        vis[curPos] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) ++ans;
    }
    cout << ans << '\n';

    return 0;
}