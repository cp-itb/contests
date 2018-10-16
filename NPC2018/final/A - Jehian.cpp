/**
 * Contest : NPC 2018 Final
 * Team    : Jehian Norman Saviero
 * Author  : Jehian Norman Saviero
 * Problem : A - Cak Jowo
 */

#include <bits/stdc++.h>

#define Jehian using
#define Norman namespace
#define Saviero std

Jehian Norman Saviero;

typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<l> sl;
typedef set<ll> sll;

#define fi first
#define se second

#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe > 0; ) x[--_qwe] = y
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x) (x), (x)+(n)
#define ALLR(x,a,b) (x)+(a), (x)+(b)+1
#define VSORT(x) sort(ALL(x))
#define SSORT(x,n) sort(ALLN(x,n))

#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)

#define scll(x) scanf("%lld", &x)
#define debug(x) cerr << #x << ": " << x << endl;

int main(){
    ll T;
    scll(T);
    for (ll tc = 1; tc <= T; ++tc) {
        ll N, M, X;
        scll(N), scll(M), scll(X);
        vll adj[N];
        map<ll, map<ll, ll> > cost;
        map<ll, map<ll, bool> > done;
        pair<ll, pll> MIN = mp(1000000000, mp(-1,-1));
        for (ll i = 0; i < M; ++i) {
            ll u, v, p;
            scll(u), scll(v), scll(p);
            adj[u].pb(v);
            adj[v].pb(u);
            if (!done[u][v]) {
                cost[u][v] = p;
                cost[v][u] = p;
                done[u][v] = 1;
                done[v]
                [u] = 1;
            } else {
                cost[u][v] = cost[v][u] = min(cost[u][v], p);
            }
            MIN = min(MIN, mp(p, mp(u,v)));
        }
        bool visit[N];
        RESET(visit);
        priority_queue< pair<ll, pll>, vector< pair<ll,pll> >, greater< pair<ll,pll> > > pq;
        pq.push(MIN);
        ll sum = pq.top().fi;
        ll val;
        pll pos;
        tie(val, pos) = pq.top();
        pq.pop();
        if (!visit[pos.fi]) {
            visit[pos.fi] = 1;
            for (auto& it : adj[pos.fi]) {
                pq.push({cost[pos.fi][it], {pos.fi, it}});
            }
        }
        if (!visit[pos.se]) {
            visit[pos.se] = 1;
            for (auto& it : adj[pos.se]) {
                pq.push({cost[pos.se][it], {pos.se, it}});
            }
        }
        while (!pq.empty()) {
            tie(val, pos) = pq.top();
            pq.pop();
            if (!visit[pos.se]) {
                sum += val;
                visit[pos.se] = 1;
                for (auto& it : adj[pos.se]) {
                    pq.push({cost[pos.se][it], {pos.se, it}});
                }
            }
        }
        if (sum <= X) {
            printf("Kasus #%lld: Untung %lld\n", tc, X-sum);
        } else {
            printf("Kasus #%lld: Rugi %lld\n", tc, sum-X);
        }
    }
    return 0;
}