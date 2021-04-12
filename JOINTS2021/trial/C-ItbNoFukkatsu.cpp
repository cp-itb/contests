#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int K = 17;
const int INF = 1e9 + 10;

int n;
int ar[N];


struct Spmin{
    int log[N + 1];
    int st[N][K + 1];

    Spmin(){
        
    }

    void setup(int * ar, int n){
        log[1] = 0;
        for (int i = 2; i <= N; i++)
            log[i] = log[i / 2] + 1;

        for (int i = 1; i <= n; i++)
            st[i][0] = ar[i];

        for (int j = 1; j <= K; j++)
            for (int i = 1; i + (1 << j) <= n + 1; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r){
        int j = log[r - l + 1];
        int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
        return minimum;
    }
};
struct Spmax{
    int log[N + 1];
    int st[N][K + 1];

    Spmax(){
        
    }

    void setup(int * ar, int n){
        log[1] = 0;
        for (int i = 2; i <= N; i++)
            log[i] = log[i / 2] + 1;

        for (int i = 1; i <= n; i++)
            st[i][0] = ar[i];

        for (int j = 1; j <= K; j++)
            for (int i = 1; i + (1 << j) <= n + 1; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r){
        int j = log[r - l + 1];
        int minimum = max(st[l][j], st[r - (1 << j) + 1][j]);
        return minimum;
    }
};
Spmin spmin;
Spmax spmax;

pii rmin[N], rmax[N];
vector<int> adj[N], radj[N];

int bit[N];
void upd(int x, int val){
    while (x < N){
        bit[x] += val;
        x += (x & (-x));
    }
}
int ask(int x){
    int ret = 0;
    while (x){
        ret += bit[x];
        x -= (x & (-x));
    }
    return ret;
}
int ask(int a, int b){
    return ask(b) - ask(a - 1);
}
ll hitung(ll a){
    return (a + 1) * a / 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    ll ans = 0;
    spmin.setup(ar, n);
    spmax.setup(ar, n);
    {
        for (int i=1;i<=n;i++){
            {
                int l = 1, r = i;
                while (l < r){
                    int m = (l + r) / 2;
                    if (spmin.query(m, i) == ar[i]){
                        r = m;
                    } else{
                        l = m + 1;
                    }
                }
                rmin[i].fi = r;
            }
            {
                int l = i, r = n;
                while (l < r){
                    int m = (l + r + 1) / 2;
                    if (spmin.query(i, m) == ar[i]){
                        l = m;
                    } else{
                        r = m - 1;
                    }
                }
                rmin[i].se = l;
            }
        }
    }
    {
        for (int i=1;i<=n;i++){
            {
                int l = 1, r = i;
                while (l < r){
                    int m = (l + r) / 2;
                    if (spmax.query(m, i) == ar[i]){
                        r = m;
                    } else{
                        l = m + 1;
                    }
                }
                rmax[i].fi = r;
            }
            {
                int l = i, r = n;
                while (l < r){
                    int m = (l + r + 1) / 2;
                    if (spmax.query(i, m) == ar[i]){
                        l = m;
                    } else{
                        r = m - 1;
                    }
                }
                rmax[i].se = l;
            }
        }
    }
    for (int i=1;i<=n;i++){
        adj[rmax[i].fi].pb(i);
        radj[rmax[i].se + 1].pb(i);
    }
    for (int i=1;i<=n;i++){
        for (auto &x : adj[i]){
            upd(x, 1);
        }
        for (auto &x : radj[i]){
            upd(x, -1);
        }
        ans += ask(rmin[i].fi, rmin[i].se);
    }
    {
        int bef = -1;
        int cnt = 0;
        for (int i=1;i<=n;i++){
            if (bef != ar[i]){
                ans -= max(0LL, hitung(cnt - 1));
                bef = ar[i];
                cnt = 1;
            } else{
                cnt++;
            }
        }
        ans -= max(0LL, hitung(cnt - 1));
    }
    cout << ans << el;

    return 0;
}