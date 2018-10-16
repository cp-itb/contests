/**
 * Contest : NPC 2018 Final
 * Team    : Jehian Norman Saviero
 * Author  : Jehian Norman Saviero
 * Problem : B - Gokemon Go
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
    ll N, M;
    cin >> N >> M;
    map<string, pll> HASH;
    ll val[N][M];
    RESET(val);
    string tmp;
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < M; ++j) {
            cin >> tmp;
            HASH[tmp] = mp(i,j);
        }
    }
    map<string, ll> VAL = {
        {"Gyaradud", 3000},
        {"Dragonidud", 2500},
        {"Pikadud", 4000},
        {"Aerodactdud", 2000},
        {"Ratattadud", 100},
        {"Caterpiedud", 110},
        {"Widdledud", 150},
        {"Pidgeydud", 100}
    };
    ll n;
    scll(n);
    string poke;
    while (n--) {
        cin >> tmp >> poke;
        ll i, j;
        tie(i,j) = HASH[tmp];
        val[i][j] += VAL[poke];
    }
    ll q;
    scll(q);
    string A, B, C;
    while (q--) {
        string Q;
        cin >> Q;
        if (Q == "Tambah") {
            cin >> A >> B >> C;
            ll i1, i2, j1, j2;
            tie(i1,j1) = HASH[A];
            tie(i2,j2) = HASH[B];
            if (i1 > i2) swap(i1,i2);
            if (j1 > j2) swap(j1,j2);
            for (ll i = i1; i <= i2; ++i) {
                for (ll j = j1; j <= j2; ++j) {
                    val[i][j] += VAL[C];
                }
            }
        } else {
            cin >> A;
            ll i, j;
            tie(i,j) = HASH[A];
            printf("%lld\n", val[i][j]);
        }
    }
    return 0;
}