 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : DryCr1TiKaL
  * Author  : Morgen Sudyanto
  * Problem : B - Laser Iron Man
  */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define LL long long
#define pii pair<LL,LL>
using namespace std;

vector<pii> v;
vector<pair<pii,pii>> s;

bool onSegment(pii a, pii b, pii c) {
    return (b.fi <= max(a.fi, c.fi) && b.fi >= min(a.fi, c.fi) &&
        b.se <= max(a.se, c.se) && b.se >= min(a.se, c.se));
}

LL orientation(pii a, pii b, pii c) {
    LL val = (b.se - a.se) * (c.fi - b.fi) - (b.fi - a.fi) * (c.se - b.se);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool intersect(pair<pii,pii> a, pair<pii,pii> b) {
    int o1 = orientation(a.fi, a.se, b.fi);
    int o2 = orientation(a.fi, a.se, b.se);
    int o3 = orientation(b.fi, b.se, a.fi);
    int o4 = orientation(b.fi, b.se, a.se);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(a.fi, b.fi, a.se)) return true;
    if (o2 == 0 && onSegment(a.fi, b.se, a.se)) return true;
    if (o3 == 0 && onSegment(b.fi, a.fi, b.se)) return true;
    if (o4 == 0 && onSegment(b.fi, a.se, b.se)) return true;

    return false;
}

bool collinear(pii a, pii b, pii c) {
    LL x1 = b.fi - a.fi;
    LL y1 = b.se - a.se;
    LL x2 = c.fi - a.fi;
    LL y2 = c.se - a.se;
    return x1 * y2 == x2 * y1;
}

LL length(pii a, pii b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

bool can(pii a, pii b) {
    for (LL i=0;i<s.size();i++) {
        if (intersect({a, b}, s[i])) return false;
    }
    return true;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL x, y;
    cin >> x >> y;
    LL n;
    cin >> n;
    for (LL i=1;i<=n;i++) {
        LL p,q;
        cin >> p >> q;
        v.pb({p, q});
    }
    LL k;
    cin >> k;
    for (LL i=1;i<=k;i++) {
        LL a,b,c,d;
        cin >> a >> b >> c >> d;
        s.pb({{a, b}, {c, d}});
    }
    LL ans = 0;
    // cerr << "--------------" << endl;
    for (LL i=0;i<n;i++) {
        if (can({x, y}, v[i])) {
            // cerr << v[i].fi << " " << v[i].se << endl;
            ans++;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

/*
5 8
8
2 5
2 7
5 2
8 3
9 4
5 5
5 6
9 6
11
3 5 3 3
5 3 5 4
5 3 6 3
7 4 7 5
6 3 5 4
7 4 8 4
8 4 8 5
8 5 7 5
4 2 4 6
3 3 4 2
4 6 3 5

------ intended
2 5
2 7
9 6
5 5
5 6

5
*/