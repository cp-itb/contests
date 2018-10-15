/**
 * Contest : NPC 2018 Final
 * Team    : Jehian Norman Saviero
 * Author  : Jehian Norman Saviero
 * Problem : D - Dual Balanced Parentheses
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

ll powMod(ll a, ll p) {
    ll res = 1;
    for (; p; p >>= 1, a = SQR(a)%MD) {
        if (p & 1) res *= a, res %= MD;
    }
    return res;
}

ll MUL(ll a, ll b) {
    return (a * b) % MD;
}

ll inv[sz];
ll fac[sz];

void PreCompute() {
    fac[0] = fac[1] = 1;
    for (ll i = 2; i < sz; ++i) {
        fac[i] = MUL(fac[i-1], i);
    }
    inv[sz-1] = powMod(fac[sz-1], MD-2);
    for (ll i = sz-1; i > 0; --i) {
        inv[i-1] = MUL(inv[i], i);
    }
}

ll eval(ll val) {
    return MUL(fac[val], MUL(inv[val/2], inv[val/2+1]));
}

int main(){
    ll T;
    scll(T);
    PreCompute();
    while (T--) {
        string s;
        cin >> s;
        map<char, int> cnt;
        for (auto& it : s) {
            ++cnt[it];
        }
        if (cnt['A'] % 2 == 0 && cnt['B'] % 2 == 0) {
            printf("%lld\n", MUL(eval(cnt['A']), eval(cnt['B'])));
        } else {
            printf("0\n");
        }
    }
    return 0;
}