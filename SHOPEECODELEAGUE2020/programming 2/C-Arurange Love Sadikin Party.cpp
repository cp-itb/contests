/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Arurange Love Sadikin Party
* Author  : Jehian Norman Saviero
* Problem : C - Connectivity
*/

/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>
 
// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std
 
Jehian Norman Saviero;
 
// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
 
// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")
 
// MACROS FOR ATTRIBUTE
#define fi first
#define se second
 
// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))
 
// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

const int N = 1e6 + 10; 

typedef tuple<char, int, int> special;

int p[N], sz[N], ans; 
stack<int> st; 

int n, k, u[N + N], v[N + N], o[N + N];
char op[N + N];

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

unordered_map<pi,int,hash_pair> cnt, mp;

int find(int u) {
	while(p[u] != u) u = p[u];
	return u;
}

void Union(int u, int v) {
	u = find(u); v = find(v); 
	if(u == v) return; 
	if(sz[u] > sz[v]) swap(u, v);
	p[u] = v;
	sz[v] += sz[u];
	ans--; 
	st.push(u);
}

void rollbax(int t) {
	while(st.size() > t) {
		int u = st.top(); st.pop(); 
		sz[p[u]] -= sz[u]; 
		p[u] = u; ans++;
	}
}

bool duplicate[N];

void solve(int l, int r) {
	if (l == r) {
		if (op[l] == '?') {
			printf("%d\n", ans);
		}
		return; 
	} 
	int m = l + r >> 1, now = st.size();
	
	for (int i = m + 1; i <= r; i++) {
		if (o[i] < l) {
			Union(u[i], v[i]); 
		}
	}
	solve(l, m); 
	rollbax(now);  
	for (int i = l; i <= m; i++) {
		if (o[i] > r) {
			Union(u[i], v[i]);
		}
	}
	solve(m + 1, r);
	rollbax(now);
}

pi curr[N << 1];
special queries[N << 1];

char tmp[4];

int main() {
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= n; i++) 
		p[i] = i, sz[i] = 1; 

	int hit = 0;
	int wkwk = 0;
	for (int i = 0; i < k; ++i) {
		scanf("%s", tmp);
		if (tmp[1] == 'U') { // PUSH
			int a, b;
			sci(a), sci(b);
			if (a > b) {
				swap(a,b);
			}
			curr[wkwk++] = {a,b};
			++cnt[{a,b}];
			if (cnt[{a,b}] == 1) {
				get<0>(queries[hit]) = '+';
				get<1>(queries[hit]) = a;
				get<2>(queries[hit++]) = b;
			}
		} else { // POP
			int a, b;
			tie(a, b) = curr[--wkwk];
			--cnt[{a,b}];
			if (cnt[{a,b}] == 0) {
				get<0>(queries[hit]) = '-';
				get<1>(queries[hit]) = a;
				get<2>(queries[hit++]) = b;
			}
		}
		get<0>(queries[hit++]) = '?';
	}
	k = hit;

	for (int i = 1; i <= k; i++) {
		tie(op[i], u[i], v[i]) = queries[i-1];
		if (op[i] == '?') continue; 
		pi x(u[i], v[i]); 
		if (mp.count(x)) {
			o[i] = mp[x];
			o[o[i]] = i; 
			mp.erase(x); 
		} else {
			mp[x] = i; 
		}
	}
	int idx = k; 
	for(auto it : mp) { 
		o[it.second] = ++idx; 
		o[idx] = it.second; 
		op[idx] = '-';
		tie(u[idx], v[idx]) = it.first; 
	}
	ans = n;
	solve(1, idx); 
	return 0;
}
