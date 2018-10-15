/**
 * Contest : NPC 2018 Final
 * Team    : Jehian Norman Saviero
 * Author  : Jehian Norman Saviero
 * Problem : H - Brokenheart Leeta
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

const ll sz = 1e6+5;
const ll MD = 1e9+7;
ll MUL(ll a, ll b) {
    return (a * b) % MD;
}

int main(){
    ll curr[sz];
    RESET(curr);
    curr[0] = curr[1] = 1;
    curr[2] = 1;
    ll now = 3;
    for (ll i = 3; i < sz; ++i) {
        curr[i] = MUL(curr[i-1], now);
        now += i;
        now %= MD;
    }
    ll T, tc = 0;
    scll(T);
    while (T--) {
        ll tmp;
        scll(tmp);
        printf("Kasus #%lld: %lld\n", ++tc, curr[tmp]);
    }
    return 0;
}